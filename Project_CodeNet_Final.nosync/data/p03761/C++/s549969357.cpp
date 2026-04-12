#include<bits/stdc++.h>

using namespace std;

const int INF=1000000000;
int cnt[100][30];

int main(){
        string s[100];
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
                for(int j=0;j<30;j++){
                        cnt[i][j]=0;
                }
        }
        for(int i=0;i<n;i++){
                cin>>s[i];
                for(int j=0;j<(int)s[i].size();j++){
                        cnt[i][s[i][j]-'a']++;
                }
        }
        int res[30];
        for(int i=0;i<30;i++){
                res[i]=INF;
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<30;j++){
                        res[j]=min(cnt[i][j], res[j]);
                }
        }
        for(int i=0;i<26;i++){
                for(int j=0;j<res[i];j++){
                        cout<<(char)('a'+i);
                }
        }
        cout<<endl;
        return 0;
}
