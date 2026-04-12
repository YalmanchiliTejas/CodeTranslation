/*
 * @Author: your name
 * @Date: 2020-01-22 19:43:36
 * @LastEditTime: 2020-01-22 19:46:30
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \code\AT2156.cpp
 */
//aeiou
#include <bits/stdc++.h>
using namespace std;
char a[5]={'a','e','i','o','u'};
int main() {
   //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  char s;
  cin>>s;
  for (int i = 0; i < 5; i++)
  {
      /* code */
      if (s==a[i])
      {
          /* code */
          puts("vowel");
          return 0;
      }
      
  }
  puts("consonant");
getchar();getchar();
    return 0;
}