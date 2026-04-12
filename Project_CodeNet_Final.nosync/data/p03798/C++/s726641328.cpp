#include <bits/stdc++.h>
using namespace std;

void SS(char*,char*);
void SW(char*,char*);
void WS(char*,char*);
void WW(char*,char*);

int flag=0,N,i;

int main(){
  cin >> N;
  char s[N],a[N];
  for(i=0;i<N;i++){
    cin >> s[i];
  }

  SS(a,s);
  if(flag==0){SW(a,s);}
  if(flag==0){WS(a,s);}
  if(flag==0){WW(a,s);}

  if(flag==0){
    cout << -1 << endl;
  }else{
    for(i=0;i<N;i++){
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
}

void SS(char* a,char* s){
  a[0]='S';a[1]='S';
  for(i=1;i<N-1;i++){
    if(a[i]=='S' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='S' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='W';
    }
  }
  if(a[i]=='S' && s[i]=='o' && a[i-1]=='S'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='W'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='W'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='S'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }
}
void SW(char* a,char* s){
  a[0]='S';a[1]='W';
  for(i=1;i<N-1;i++){
    if(a[i]=='S' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='S' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='W';
    }
  }
  if(a[i]=='S' && s[i]=='o' && a[i-1]=='S'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='W'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='W'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='S'){
    if((s[0]=='o' && a[i]==a[1]) || (s[0]=='x' && a[i]!=a[1])){flag=1;};
  }
}
void WS(char* a,char* s){
  a[0]='W';a[1]='S';
  for(i=1;i<N-1;i++){
    if(a[i]=='S' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='S' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='W';
    }
  }
  if(a[i]=='S' && s[i]=='x' && a[i-1]=='S'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='S' && s[i]=='o' && a[i-1]=='W'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='W'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='S'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }
}
void WW(char* a,char* s){
  a[0]='W';a[1]='W';
  for(i=1;i<N-1;i++){
    if(a[i]=='S' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='S' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='S' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='S'){
      a[i+1]='W';
    }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='W'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='S'){
      a[i+1]='S';
    }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='W'){
      a[i+1]='W';
    }
  }
  if(a[i]=='S' && s[i]=='x' && a[i-1]=='S'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='S' && s[i]=='o' && a[i-1]=='W'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='x' && a[i-1]=='W'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }else if(a[i]=='W' && s[i]=='o' && a[i-1]=='S'){
    if((s[0]=='x' && a[i]==a[1]) || (s[0]=='o' && a[i]!=a[1])){flag=1;};
  }
}