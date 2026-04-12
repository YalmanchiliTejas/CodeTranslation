#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c[n][26];
    memset(c,0,sizeof c);
    vector<string> v(n);
    for(int i=0;i<n;++i){
    	string s;
    	cin >> s;
    	v[i]=s;
    }
    for(int i=0;i<n;++i){
    	for(int j=0;j<v[i].length();++j){
    		int t=v[i][j]-97;
    		c[i][t]++;
    	}
    }
    string s;
    for(char x='a';x<='z';++x){
    	int m=12345678;
    	for(int i=0;i<n;++i){
    	for(int j=0;j<v[i].length();++j){
    		if(c[i][x-97] < m)m=c[i][x-97];
    	}
    }
    string temp;
    for(int i=0;i<m;++i){
    	temp+=x;
    }
    s+=temp;
}
cout << s <<endl;

    return 0;

}
