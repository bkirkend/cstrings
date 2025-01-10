#include "string.h"

static void swap(char *s, char *c){
  char temp = *s;
  *s = *c;
  *c = temp;
}

void* mem_set(void *ptr, int value, size_t size){
  unsigned char *mem = (unsigned char *)ptr;

  for (size_t i = 0; i < size; i++){
    mem[i] = (unsigned char) value;
  }

  return ptr;
}

void* mem_cpy(void *tgt, const void *src, size_t size){
  if (!tgt || !src) return NULL;
  unsigned char *tgt_mem = (unsigned char *) tgt;
  unsigned char *src_mem = (unsigned char *) src;
  for (size_t i = 0; i < size; i++) tgt_mem[i] = src_mem[i];
  return tgt;
}

bool mem_cmp(const void *ptr1, const void *ptr2, size_t size){
  if (!ptr1 || !ptr2) return false;
  unsigned char *mem1 = (unsigned char *) ptr1;
  unsigned char *mem2 = (unsigned char *) ptr2;
  for (size_t i = 0; i < size; i++){
    if (mem1[i] != mem2[i]) return false;
  }
  return true;
}

bool str_cmp(const char *str1, const char *str2){
  while(*str1 != '\0'){
    if(*str1++ != *str2++){
      return false;
    }
  }
  return *str2 == '\0';
}

void str_cpy(const char *src, char *tgt){
  while((*tgt++ = *src++));
}

void str_n_cpy(const char *src, char *tgt, size_t n){
  for (size_t i = 0; i < n && *src; i++){
    tgt[i] = src[i];
  }
}

size_t str_len(const char *str){
  if (str_empty(str)) return 0;
  size_t len = 0;
  while(*str++) len++;
  return len;
}

bool str_empty(const char* str){
  return !str || *str == '\0'; 
}

char* str_dup(const char *str){
  size_t len = str_len(str);
  char *copy = malloc((len + 1) * sizeof(char));
  if(!copy) return NULL;

  char *s = copy;
  while((*s++ = *str++));
  return copy;
}

char* str_cat_alloc(const char *tgt, const char *src){
  size_t tgt_len = str_len(tgt);
  size_t src_len = str_len(src);
  size_t total_len = tgt_len + src_len + 1;

  char *cat = malloc(total_len * sizeof(char));
  if(!cat) return NULL;

  char *start = cat;
  while((*cat++ = *tgt++));
  cat--;
  while((*cat++ = *src++));
  return start;
}

void str_cat(const char *src, char *tgt){
  while((*tgt++));
  tgt--;
  while((*tgt++ = *src++));
}

char* str_reverse(const char* str){
  size_t len = str_len(str);

  char *rev = malloc((len + 1) * sizeof(char));
  rev[len] = '\0';

  if (!str) return rev;
  
  char *p = rev;
  for(size_t i = 0; i < len; i++){
    *p++ = str[len - i - 1];
  }

  return rev;
}

char* str_find(const char *haystack, const char *needle){
  if (str_empty(needle)) return (char*) haystack;
  for (; *haystack != '\0'; haystack++){
    const char *h = haystack;
    const char *n = needle;
    while(*h && *h == *n){
      h++;
      n++;
    }
    if(*n == '\0') return (char*) haystack;
  }
  return NULL;
}

