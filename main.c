#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------prototype----------------------------------------

FILE* load_dictionary(char*);
int get_number_of_word(FILE*);
char** array_init(FILE*, int);
void print_array(char**, int);
void free_memory(char**, int);

// --------------------------------main----------------------------------------

int main(void) {

  FILE* dictionary_addr;
  int number_of_word;
  char** dictionary_array;

  dictionary_addr = load_dictionary("dictionary.txt");
  number_of_word = get_number_of_word(dictionary_addr);
  dictionary_array = array_init(dictionary_addr, number_of_word);

  print_array(dictionary_array, number_of_word);
  fclose(dictionary_addr);
  free_memory(dictionary_array, number_of_word);

  return 0;
}

// --------------------------------function----------------------------------------

FILE* load_dictionary(char* path) {
  FILE* dictionary_addr = fopen(path, "r");

  if(dictionary_addr == NULL) {
    printf("Error: unable to load %s", path);
    exit(1);
  }

  return dictionary_addr;
}

// ------------------------------------------------------------------------

int get_number_of_word(FILE* dictionary_addr) {
  int number_of_word;

  fscanf(dictionary_addr, "%d", &number_of_word);

  return number_of_word;
}

// ------------------------------------------------------------------------

char** array_init(FILE* dictionary_addr, int number_of_word) {
  char** dictionary_array;
  char word[50];
  int i;

  dictionary_array = (char**) malloc(number_of_word * sizeof(char*));

  for(i = 0; i < number_of_word; i++) {
    fscanf(dictionary_addr, "%s", word);
    dictionary_array[i] = (char*) malloc((strlen(word) + 1) * sizeof(char));
    strcpy(dictionary_array[i], word);
  }

  return dictionary_array;
}

// ------------------------------------------------------------------------

void free_memory(char** dictionary_array, int number_of_word) {
  int i = 0;

  for(i = 0; i < number_of_word; i++) {
    free(dictionary_array[i]);
  }

  free(dictionary_array);
}

// ------------------------------------------------------------------------

void print_array(char** dictionary_array, int number_of_word) {
  int i;
  for(i = 0; i < number_of_word; i++) {
    printf("%s ", dictionary_array[i]);
  }
}