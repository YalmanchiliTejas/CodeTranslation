#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;


int main(){
  
  int N;
  cin>>N;
  int d[300000];
  for(int i=0;i<N;i++){
    cin>>d[i];
  }
  int D[600000];
  for(int i=0;i<N*2-1;i++){
    if(i<N){
      D[i]=d[i];
    }
    if(i>=N){
      D[i]=d[N*2-i-2];
    }
  }
  int judge[600000];
  judge[0]=1;
  for(int i=1;i<N*2-1;i++){
    judge[i]=0;
  }
  int jump=0;
  for(int i=0;i<N;i++){
    if(i<=jump){
        judge[i]=1;
      }
    if(judge[i]==1){
      jump=max(jump,i+D[i]/10);
    }
  }
  if(judge[N-1]==1){
    for(int i=N-1;i<N*2-1;i++){
      if(i<=jump){
        judge[i]=1;
      }
      if(judge[i]==1){
        jump=max(jump,i+D[i]/10);
      }
    }
  }
  if(judge[N*2-2]==1){
    cout<<"yes"<<endl;
  }
  else{
    cout<<"no"<<endl;
  }
  
  /*int x,y;
  cin>>x>>y;
  int gcd=0;
  for(int i=1;i<=min(x,y);i++){
    if(x%i==0 && y%i==0){
      gcd=max(gcd,i);
    }
  }
  cout<<x+y+1-gcd<<endl;*/
  
  
  /*int a,b,N;
  cin>>a>>b;
  cin>>N;
  int s[100],f[100];
  for(int i=0;i<N;i++){
    cin>>s[i]>>f[i];
  }
  int judge=0;
  for(int i=0;i<N;i++){
      if(s[i]<=a && f[i]>a){
        judge=judge+1;
      }
      if(s[i]<b && f[i]>=b){
        judge=judge+1;
      }
      if(a<=s[i] && b>s[i]){
        judge=judge+1;
      }
      if(a<f[i] && b>=f[i]){
        judge=judge+1;
      }
  }
  if(judge==0){
    cout<<0<<endl;
  }
  else{
    cout<<1<<endl;
  }*/
  
 /* int X;
  cin>>X;
  if(X%7==0){
    cout<<"thu"<<endl;
  }
  if(X%7==1){
    cout<<"fri"<<endl;
  }
  if(X%7==2){
    cout<<"sat"<<endl;
  }
  if(X%7==3){
    cout<<"sun"<<endl;
  }
  if(X%7==4){
    cout<<"mon"<<endl;
  }
  if(X%7==5){
    cout<<"tue"<<endl;
  }
  if(X%7==6){
    cout<<"wed"<<endl;
  }
 */
	
	/*int m,f,b;
	cin>>m>>f>>b;
	if(b-m<=0){
		cout<<0<<endl;
	}
	if(b-m>0 && b-m<=f){
		cout<<b-m<<endl;
	}
	if(b-m>0 && b-m>f){
		cout<<"NA"<<endl;
	}*/
	/*int a,b;
	cin>>a>>b;
	cout<<(a+b)/2<<endl;*/
	
	/*random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> rnd3(1, 3);
	
	string p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	
	int t = rnd()%3;
	
	if(t == 0){
		cout << "1:" << p1 << ',' << p2 << endl;
		cout << "2:" << p3 << ',' << p4 << endl;
	}
	if(t == 1){
		cout << "1:" << p1 << ',' << p3 << endl;
		cout << "2:" << p2 << ',' << p4 << endl;
	}
	if(t == 2){
		cout << "1:" << p1 << ',' << p4 << endl;
		cout << "2:" << p2 << ',' << p3 << endl;
	}*/
	
	/*
	switch(type){
		case 0:
			cout << "1:" << p1 << ',' << p2 << endl;
			cout << "2:" << p3 << ',' << p4 << endl;
			break;
		case 1:
			cout << "1:" << p1 << ',' << p3 << endl;
			cout << "2:" << p2 << ',' << p4 << endl;
			break;
		case 2:
			cout << "1:" << p1 << ',' << p4 << endl;
			cout << "2:" << p2 << ',' << p3 << endl;
			break;
	}
	*/
	
	
	return 0;
}

