#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#define pan(i,n) for(int i=0;i<n;i++)
#define ll long long int
using namespace std;

int main(){
    int n,k;
    string s;

    cin>>n;
    cin>>s;
    cin>>k;
    char c[n];
    strcpy(c,s.c_str());
    char a=c[k-1];
    pan(i,n){
    	if(c[i]!=a){
    		cout<<"*";
    	}
    	else{
    	    cout<<c[i];
    	}
    }
}
