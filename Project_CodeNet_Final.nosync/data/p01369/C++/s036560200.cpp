#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lpin(a,i,n) for(int i=0;i<n;i++){cin>>a[i];}
int  main(){
  vector<char> x;
  x.push_back('y');
  x.push_back('h');
  x.push_back('n');
  x.push_back('m');
  x.push_back('j');
  x.push_back('u');
  x.push_back('i');
  x.push_back('k');
  x.push_back('l');
  x.push_back('o');
  x.push_back('p');
  while(1){
    char a;
    int count=0,memo=0;
    while(1){
      scanf("%c",&a);
      if(a=='#') return 0;
      if('a'<=a &&a<='z') 1;
      else {
	break;
      }
      if(find(x.begin(),x.end(),a)!=x.end()){
	if(memo==0){
	  memo=1;
	}
	else if(memo==2){
	  count++;
	  memo=1;
	}
      }
      else{
	if(memo==0) memo=2;
	else if(memo==1){
	  count++;
	  memo=2;
	}
      }
    }
    cout<<count<<endl;
  }
  return 0;
}

