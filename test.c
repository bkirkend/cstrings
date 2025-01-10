#include <stdio.h>
#include "string.h"

int main(int argc, char** argv){
  char str1[] = "hello ";
  char str2[] = "world";
  printf("str1: %s | size: %zu\n", str1, str_len(str1));
  printf("str2: %s | size: %zu\n", str2, str_len(str2));
  char *comb = str_cat_alloc(str1, str2);
  printf("cat: %s | size: %zu\n", comb, str_len(comb));

  char *new_comb = malloc((str_len(comb) + 1) * sizeof(char));
  str_cpy(str1, new_comb);
  printf("after copy: %s\n", new_comb);
  str_cat(str2, new_comb);
  printf("new cat: %s | size: %zu\n", new_comb, str_len(new_comb));
  
  char *rev = str_reverse(comb);
  printf("rev: %s | size: %zu\n", rev, str_len(rev));

  char* longString = "message about something";
  char* notFoundString = "message about a different thing";
  char* findString = "some";
  char* find_ptr = str_find(notFoundString, findString);
  if(find_ptr){
    printf("found %s in %s\n", find_ptr, longString);
  } else {
    printf("string not found\n");
  }
  
  free(comb);
  free(new_comb);
  free(rev);
  return 0;
}
