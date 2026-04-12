#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  char s[n];
  scanf("%s",s);
  char a[n];
  a[0]='S';a[1]='S';
  for(int i=2;i<n;i++){
    if(s[i-1]=='o'){
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      } else {
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      }
    } else {
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      } else {
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      }
    }
  }
  if(s[0]=='o' && s[n-1]=='o'){
    if(a[n-1]=='S' && a[n-2]=='S'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='o' && s[n-1]=='x'){
    if(a[n-1]=='S' && a[n-2]=='W'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='o'){
    if(a[n-1]=='W' && a[n-2]=='W'){
      printf(a);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='x'){
    if(a[n-1]=='W' && a[n-2]=='S'){
      printf(a);
      return 0;
    }
  }
  a[0]='W';a[1]='S';
  for(int i=2;i<n;i++){
    if(s[i-1]=='o'){
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      } else {
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      }
    } else {
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      } else {
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      }
    }
  }
  if(s[0]=='o' && s[n-1]=='o'){
    if(a[n-1]=='W' && a[n-2]=='S'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='o' && s[n-1]=='x'){
    if(a[n-1]=='W' && a[n-2]=='W'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='o'){
    if(a[n-1]=='S' && a[n-2]=='W'){
      printf(a);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='x'){
    if(a[n-1]=='S' && a[n-2]=='S'){
      printf(a);
      return 0;
    }
  }
  a[0]='S';a[1]='W';
  for(int i=2;i<n;i++){
    if(s[i-1]=='o'){
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      } else {
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      }
    } else {
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      } else {
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      }
    }
  }
  if(s[0]=='o' && s[n-1]=='o'){
    if(a[n-1]=='W' && a[n-2]=='W'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='o' && s[n-1]=='x'){
    if(a[n-1]=='W' && a[n-2]=='S'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='o'){
    if(a[n-1]=='S' && a[n-2]=='S'){
      printf(a);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='x'){
    if(a[n-1]=='S' && a[n-2]=='W'){
      printf(a);
      return 0;
    }
  }
  a[0]='W';a[1]='W';
  for(int i=2;i<n;i++){
    if(s[i-1]=='o'){
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      } else {
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      }
    } else {
      if(a[i-1]=='S'){
        if(a[i-2]=='S') a[i]='W';
        else a[i]='S';
      } else {
        if(a[i-2]=='S') a[i]='S';
        else a[i]='W';
      }
    }
  }
  if(s[0]=='o' && s[n-1]=='o'){
    if(a[n-1]=='S' && a[n-2]=='W'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='o' && s[n-1]=='x'){
    if(a[n-1]=='S' && a[n-2]=='S'){
      for(int i=0;i<n;i++)
        printf("%c",a[i]);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='o'){
    if(a[n-1]=='W' && a[n-2]=='S'){
      printf(a);
      return 0;
    }
  }else if(s[0]=='x' && s[n-1]=='x'){
    if(a[n-1]=='W' && a[n-2]=='W'){
      printf(a);
      return 0;
    }
  }
  printf("-1");
  return 0;
}