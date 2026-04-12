#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(26));

    for(int i=0;i<n;i++){
        string s;
        cin>> s;
        for(int j=0;j<s.size();j++){
            int tmp = s[j] - 'a';
            v[i][tmp]++;
        }
    }

    string str(" ");

    for(int j=0;j<26;j++){
        int mi=1e8;
        bool ok=true;
        for(int i=0;i<n;i++){
            if(v[i][j]==0){ok=false;break;}

            mi = min(mi,v[i][j]);
        }
        if(ok)
            for(int i=0;i<mi;i++){
                if(str==" ")
                    str = j + 'a';
                else
                    str += j + 'a';
            }
    }

    sort(str.begin(),str.end());

    cout<<str;
}
