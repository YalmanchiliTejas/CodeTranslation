#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int h,w;
bool vis[105],ans[105];
char s[105][105];
int main() {
     
    cin>>h>>w;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++) {
            cin>>s[i][j];
        }
    for(int i=1,flag=0;i<=h;i++,flag=0) {
        for(int j=1;j<=w;j++) {
            if(s[i][j]=='#')
                {   
                    flag=1;
                    break;
                }
            }
                if(!flag)
                vis[i]=1;
        }
    for(int i=1,flag=0;i<=w;i++,flag=0) {
        for(int j=1;j<=h;j++) {
            if(s[j][i]=='#') {
                flag=1;
                break;
            }

        }
           if(!flag)
            ans[i]=1;
    }
    for(int i=1;i<=h;i++){
        if(vis[i])
        continue;
       for(int j=1;j<=w;j++)
       { if(ans[j])
        continue;
        cout<<s[i][j];
        }
        cout<<endl;
    }

}