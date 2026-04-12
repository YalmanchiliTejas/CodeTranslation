#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main(){
	unsigned int x,y,n;
	cin>>n;
    x=n*800;
    if(n>=15)
    cout<<x-(n/15*200);
    else
	cout<<x;
	return 0;
}