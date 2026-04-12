#include<bits/stdc++.h>
using namespace std;

int foo(string N){
	int size = N.size();
	int n = 0, x = pow(10,size-1);
	
	for(int i = 0; i < size; i++, x/=10){
		n += (N[i] - '0')*x;
	}
	if(to_string(n).size() != size) return false;
	else if( 255 >= n) return true;
	else return false;
}

int main(){
	string S;
	int size, count = 0;
	cin>>S;
	
	size = S.size();
	
	for(int i = 0; i < size;i++){
		for(int j = i+1; j < size; j++){
			for(int k = j+1; k < size; k++){
				bool tempa = true;
				string temp;
				for(int n = 0; n <= i; n++){
						temp += S[n];
				}
				if(foo(temp) == false)tempa = false;
				temp.clear();
				for(int n = i+1; n <= j; n++){
						temp += S[n];
				}
				if(foo(temp) == false)tempa = false;
				
				temp.clear();
				
				for(int n = j+1; n <= k; n++){
						temp += S[n];
				}
				if(foo(temp) == false)tempa = false;
				temp.clear();
				for(int n = k+1; n < size; n++){
						temp += S[n];
				}
				if(foo(temp) == false)tempa = false;
				
				
				if(tempa == true) count++;
			}
		}
	}
	
	cout<<count<<endl;
	
	return 0;
}
