#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a;
    for(int i=0;i<h;i++){
        a.push_back(vector<char>());
        string s;
        cin>>s;
        for(int j=0;j<w;j++){
            a[i].push_back(s[j]);
        }
    }
    vector<bool> hb(h),wb(w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                hb[i]=true;
                wb[j]=true;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(!hb[i])continue;
        for(int j=0;j<w;j++){
            if(!wb[j])continue;
            cout<<(a[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
