//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
typedef long long LL;
using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000")

/*
题意：
对于每个 headline ，可以抠出一些字符然后重新组合成一个字符串。
要求找到一个最长的，字典序最小的字符串，能被所有的 headline 包含。
思路：
每次处理
*/
const int INF=0x3f3f3f3f;
int num[30],n;

void solve(char *str){
    int temp[30];
    int len=strlen(str);
    memset(temp,0,sizeof(temp));
    for(int i=0;i<len;i++)
        temp[str[i]-'a']++;
    for(int i=0;i<26;i++)
        num[i]=min(num[i],temp[i]);
}

int main(){
    char str[55];
    scanf("%d",&n);
    memset(num,INF,sizeof(num));
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        solve(str);
    }
    string ans="";
    for(int i=0;i<26;i++){
        char x='a'+i;
        while(num[i]){
            ans.push_back(x);
            num[i]--;
        }
    }
    cout<<ans;
    return 0;
}

