#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};*/
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll r,c;
     char arr[105][105];
     cin>>r>>c;
     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             cin>>arr[i][j];
         }
     }
     for(int i=0;i<r;i++)
     {
         ll cnt=0;
         for(int j=0;j<c;j++)
         {
             if(arr[i][j]=='.')
                cnt++;
         }
        // cout<<cnt<<endl;
         if(cnt==c)
         {
             for(int j=0;j<c;j++)
         {
             arr[i][j]='x';
         }
         }
     }
     for(int i=0;i<c;i++)
     {
         ll cnt=0;
         for(int j=0;j<r;j++)
         {
             if(arr[j][i]=='.'|| arr[j][i]=='x')
                cnt++;
         }
         if(cnt==r)
         {
             for(int j=0;j<r;j++)
         {
             arr[j][i]='x';
         }
         }
     }
     for(int i=0;i<r;i++)
     {
         ll pk=0;
         for(int j=0;j<c;j++)
         {
             if(arr[i][j]!='x')
                cout<<arr[i][j],pk++;
         }
         if(pk!=0)
            cout<<endl;
     }


}
