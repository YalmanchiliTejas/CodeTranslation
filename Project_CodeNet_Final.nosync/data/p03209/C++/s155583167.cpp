#include <bits/stdc++.h>
using namespace std;
long long N;
long long X;
vector<long long> l,p;

long long func(long N, long long X){
  	if(N==0){
      	if(X<=0){
         	return 0; 
        }
      	else{
         	return 1; 
        }
    }
 	else if(X <= l.at(N-1)+1){
     	return func(N-1, X-1); 
    }
  	else{
     	return p.at(N-1) + func(N-1, X-l.at(N-1)-2)+1; 
    }
  
}

int main(){
 	//int N, X;
  	cin >> N >> X;
  	//vector<int> l(N),p(N);
  	l.push_back(1);
  	p.push_back(1);
  	for(int i=1; i <= N; ++i){
      	l.push_back(3+2*l.at(i-1));
      	p.push_back(1+2*p.at(i-1));
    }
  	cout << func(N,X) << endl;
}