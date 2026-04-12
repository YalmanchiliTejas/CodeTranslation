#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair

vector<int> ed[100001];
int rem[100001];
void dfs(int x,int p){

int i;
for(i=0;i<ed[x].size();i++){

    int o=ed[x][i];
    if(o!=p){

        dfs(o,x);

        if(rem[x]==0){

            if(rem[o]==0)
            {

                rem[o]=1;
                rem[x]=1;

            }

        }


    }




}



}
int main(){
int n;
cin>>n;
int i;
for(i=1;i<n;i++)
{

    int x,y;
    cin>>x;
    cin>>y;
    ed[x].pb(y);
    ed[y].pb(x);

}


dfs(1,0);
int co=0;
for(i=1;i<=n;i++){

    if(rem[i])
        co++;



}

if(co==n)
    cout<<"Second"<<endl;
else
    cout<<"First"<<endl;
return 0;

}
