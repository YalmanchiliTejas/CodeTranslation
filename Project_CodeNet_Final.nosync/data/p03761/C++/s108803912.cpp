#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];

    vector<vector<int>> cnt(n,vector<int>(26));
    vector<int> mincnt(26);
    fill(mincnt.begin(),mincnt.end(),100);
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].size();j++){
            cnt[i][s[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            mincnt[j]=min(mincnt[j],cnt[i][j]);
        }
    }

    for(int i=0;i<26;i++){
        if(mincnt[i]==0)continue;
        for(int j=0;j<mincnt[i];j++){
            cout<<char('a'+i);
        }
    }
    cout<<endl;
}