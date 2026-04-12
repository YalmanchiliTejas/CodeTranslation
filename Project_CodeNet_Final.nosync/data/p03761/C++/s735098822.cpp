#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

int n;
string str[53];
int cnt[53][30];
int res[30];

int main(){
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<=26;i++) res[i]=99999;
    for(int i=0;i<n;i++){
        cin>>str[i];
        for(int j=0;j<str[i].size();j++){
            cnt[i][str[i][j]-'a']++;
        }
    }
    for(int j=0;j<26;j++){
        for(int i=0;i<n;i++){
            res[j]=min(res[j],cnt[i][j]);
        }
        if(res[j]) while(res[j]) { printf("%c",'a'+j);res[j]--;};
    }
    cout <<endl;
    
    return 0;
}
