#include <bits/stdc++.h>
using namespace std;
 
#define MD 1000000007
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    int data[51][26]={0};//アルファベットの出現回数格納
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++){
            data[i][s[i][j]-'a']++;
        }
    }
    int m=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                m=data[j][i];
            }else{
                m=min(m,data[j][i]);
            }
        }
        for(int k=0;k<m;k++){
            char t='a';
            t+=i;
            cout<<t;
        }
    }
    cout<<endl;
           
    return 0;
}