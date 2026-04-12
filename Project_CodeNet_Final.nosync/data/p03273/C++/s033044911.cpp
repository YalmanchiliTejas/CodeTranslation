#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int h,w;
    cin>>h>>w;
    vector<vector<int>> a;
    for(int i=0;i<h;i++){
        a.push_back(vector<int>());
        string s;
        cin>>s;
        for(int j=0;j<w;j++){
            a[i].push_back(s[j]=='.'?0:1);
        }
    }
    vector<bool> hb(h),wb(w);
    for(int i=0;i<h;i++){
        bool b=false;
        for(int j=0;j<w;j++){
            if(a[i][j]==1)b=true;
        }
        if(!b)hb[i]=true;
    }
    for(int i=0;i<w;i++){
        bool b=false;
        for(int j=0;j<h;j++){
            if(a[j][i]==1)b=true;
        }
        if(!b)wb[i]=true;
    }
    for(int i=0;i<h;i++){
        if(hb[i])continue;
        for(int j=0;j<w;j++){
            if(wb[j])continue;
            cout<<(a[i][j]==1?'#':'.');
        }
        cout<<endl;
    }
    return 0;
}
