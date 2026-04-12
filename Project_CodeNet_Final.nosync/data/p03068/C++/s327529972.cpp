#include "iostream"
#define STR_MAX_LEN 10
#define REPLACE_CHAR '*'

int main()
{
  int n, k;
  char str[STR_MAX_LEN];
  scanf("%d%s%d", &n, str, &k);
  
  char output[STR_MAX_LEN];
  int i=0;
  for (; str[i]!='\0'; i++)
  {
    if ( str[i] == str[k-1] )
      output[i] = str[i];
    else
      output[i] = REPLACE_CHAR;
  }
  output[i] = '\0';
  
  printf("%s", output);
}
