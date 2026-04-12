#include<algorithm>
#include<iostream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,(n))
#define MAX_line 40

int stat[MAX_line];
char N[MAX_line];

bool input(){
  REP(i,MAX_line)stat[i]=0;
  REP(i,MAX_line)N[i]=' ';
  cin>>N;
  return (N[0]!='#');
}

void solve(){
  for(int i=0;N[i]!='\0';i++){
    stat[i]=2;
    switch(N[i]){
      case 'y':
      case 'u':
      case 'i':
      case 'o':
      case 'p':
      case 'h':
      case 'j':
      case 'k':
      case 'l':
      case 'n':
      case 'm':
          stat[i]=1;
          break; 
	}
  }
    int c=0;
    for(int i=0;stat[i+1]!=0;i++){
      if(stat[i]!=stat[i+1])c++;
    }
  
    cout<<c<<endl;
}


int main(){
  while(input()){
	  solve();
  }
}

