#include<bits/stdc++.h>
using namespace std;
long long int a[3005];
long long int ans[3005][3005][2];
long long int game(int i, int j, int player){
    if(i>j)
        return 0;
    if(ans[i][j][player-1]!=-1)
        return ans[i][j][player-1];
    if(player==1)
        return ans[i][j][player-1] = max(game(i+1,j,2)+a[i],game(i,j-1,2)+a[j]);
    return ans[i][j][player-1] = min(game(i+1,j,1)-a[i],game(i,j-1,1)-a[j]);
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<3005;i++)
        for(int j=0; j<3005; j++)
            for(int k=0; k<2; k++)
                ans[i][j][k] = -1;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    cout << game(1,n,1);
}