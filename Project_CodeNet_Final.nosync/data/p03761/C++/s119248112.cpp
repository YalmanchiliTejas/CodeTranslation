#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>


using namespace std;

int main(){

int n;
cin>>n;
int alpha[n][26]={};//0で初期化

int Alpha[26];

for(int i=0;i<n;i++){
string s;
cin>>s;
    for(int k=0;k<s.size();k++){
        int t=s[k]-'a';
        alpha[i][t]++;
    }
}
for(int k=0;k<26;k++){
    Alpha[k]=100;
    for(int i=0;i<n;i++){
    Alpha[k]=min(Alpha[k],alpha[i][k]);
    }
}

for(int i=0;i<26;i++){
    for(int k=0;k<Alpha[i];k++){
        char c='a'+i;
        cout<<c;
    }
}

 return 0;
}