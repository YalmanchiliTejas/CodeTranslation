#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <stdlib.h>
#include<string>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	if(A+B<=C*2){
		cout<<A*X+B*Y<<endl;
		return 0;
	}
	if(X<Y){
		cout<<min(Y*2*C,X*2*C+(Y-X)*B)<<endl;
	}else{
		cout<<min(X*2*C,Y*2*C+(X-Y)*A)<<endl;
	}

}