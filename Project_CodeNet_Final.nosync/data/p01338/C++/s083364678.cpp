#include<iostream>
#include<array>
#include<map>
#include<algorithm>

using namespace std;

typedef array<int,5> A;

void rot(int &i,int s){
  if(i){
    i+=s;
    if(i>=5){
      i-=4;
    }
  }
}

int score(A a){
  int s=0;
  for(auto e:a){
    int t[]={0,0,60,70,80};
    s+=t[e];
  }
  return s;
}

int main(){
  int n;
  cin>>n;
  while(n--){
    array<A,5> g;
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	cin>>g[i][j];
      }
    }
    map<A,int> m[5];
    m[0][g[0]]=0;
    for(int i=0;i<4;i++){
      for(auto e:m[i]){
	int a[4];
	for(a[0]=0;a[0]<4;a[0]++){
	  for(a[1]=0;a[1]<4;a[1]++){
	    for(a[2]=0;a[2]<4;a[2]++){
	      for(a[3]=0;a[3]<4;a[3]++){
		A u=e.first;
		A l=g[i+1];
		for(int j=0;j<4;j++){
		  rot(u[j],a[j]);
		  rot(u[j+1],a[j]);
		  rot(l[j],a[j]);
		  rot(l[j+1],a[j]);
		}
		auto d=m[i+1][l];
		m[i+1][l]=max(d,e.second+score(u));
	      }
	    }
	  }
	}
      }
    }
    int mx=0;
    for(auto e:m[4]){
      mx=max(mx,e.second+score(e.first));
    }
    cout<<mx<<endl;
  }
}