#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define vi vector<int>

#define ll long long int

int ctoi(char c) {return c-'0';}
int ord(char c) {return c-'a';}
int len(string s) {return s.length();}
int itoc(int i) {return i+'a';}

int main() {
int N;
cin>>N;
if(N==7 or N==5 or N==3) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}
