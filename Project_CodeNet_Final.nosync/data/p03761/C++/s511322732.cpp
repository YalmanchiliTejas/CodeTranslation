#include <bits/stdc++.h>
#define maxs 2020202
#define ll long long
#define mme(i,j) memset(i,j,sizeof(i))
using namespace std;
int ans[200];
string s1,s2;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        fill(ans,ans+100,INT_MAX);
        int b[130];
        for(int i=1;i<=n;i++){
            cin>>s1;
            mme(b,0);
            int id,sz = s1.size();
            for(int j=0;j<sz;j++){
                id =s1[j]-'a';
                b[id]++;
            }
            for(int k=0;k<26;k++){
                ans[k]=min(ans[k],b[k]);
            }
        }

        for(int i=0;i<26;i++){
            for(int k=0;k<ans[i];k++){
                char c=(i+'a');
                printf("%c",c);
            }
        }
        puts("");
    }
    return 0;
}