#include<bits/stdc++.h>
#include <math.h>
#include<iostream>
#include <string>
using namespace std;
typedef long long ll;
#define pb pushback
#define fr(i,n) for(int i=0;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)


int main() {
    int x,y,z;
	cin >> x>> y>> z;
    string ans;
    if((y*10+z)%4==0)ans="YES";
    else ans = "NO";
      cout << ans << endl;
}