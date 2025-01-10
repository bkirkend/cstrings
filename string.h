#include <stdbool.h>
#include <stdlib.h>

//helper
static void swap(char *s, char *c);

//mem functions
//TODO:
void* mem_set(void *ptr, int value, size_t size);
void* mem_cpy(void *tgt, const void *src, size_t size);
bool mem_cmp(const void *ptr1, const void *ptr2, size_t size);

//str functions
bool str_cmp(const char *str1, const char *str2);
void str_cpy(const char *src, char *tgt);
void str_n_cpy(const char *src, char *tgt, size_t n);
size_t str_len(const char *str);
bool str_empty(const char* str);
char* str_dup(const char *str);
char* str_cat_alloc(const char *tgt, const char *src);
void str_cat(const char *src, char *tgt);
char* str_reverse(const char* str);
char* str_find(const char *haystack, const char *needle);

//TODO:
/*char* str_tok(char *str, const char *delim);*/
/*char** str_split(const char *str, const char *delim, int *size);*/
/*char* str_join(const char **str_list, const int size, const char *delim);*/
