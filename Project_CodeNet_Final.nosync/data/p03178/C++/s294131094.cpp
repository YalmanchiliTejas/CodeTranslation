#include <bits/stdc++.h>
using namespace std;
#define int long long
#define for_(i,n) for(int i=0;i<n;++i)
#define for_1(i,n) for(int i=1;i<=n;++i)
const int mod= 1e9 +7;
const int inf=1e7;
int n;
int d;string k;
int len;



/*
digit dp:
indx 0 to len-1,

flag =1, already smaller possile digits  0 to 9 
flag = 0,not already smaller, possile digits 0 to k[indx] 
sum= sum till now

rem= sum%D, can have value from 0 to D-1

recurrence
dp[indx][rem][flag] += dp[indx-1][newRem][newFlag]
--> range = flag==1 ? 9 : k[indx];
we put 0 to i at ans[indx-1]
    for i in 0 to range    
        --> newFlag = (!flag && k[indx]>i )|| flag ? 1: 0;
        
        --> newRem  =  (oldsum+i)%D = (rem+i%D)%D 
*/


/******************* recursive approach ***************************
int dp[10000][100][2];
int solve(int indx, int rem, int flag){
    if(indx==-1) return (rem%d==0);
    //else if(indx<0) {cout<<"in1 \n";return 0;}     
    else if(dp[indx][rem][flag]!=-1) {//cout<<"in \n";
    return dp[indx][rem][flag];}

    else{
        int val=0;
        int range =(flag==1)?9:(k[len-1-indx]-'0');
       // cout<<indx<<" "<<range<<" "<<flag<<endl;
        for_(i,range+1)
        {   int newRem = (rem+i%d)%d;
            int newFlag= ((!flag && (k[len-1-indx]-'0')>i )|| flag )? 1: 0;;
            val= (val + solve(indx-1,newRem,newFlag))%mod;
        }
        dp[indx][rem][flag] = val;
        return dp[indx][rem][flag];
    }
    
}
******************* recursive approach ***************************/


main()
{
  
    cin>>k; cin>>d;
    len=k.length();
    
    //******************* recursive approach ***************************//
   /*
   memset(dp, -1, sizeof(dp));
   int ans= solve(len-1, 0, 0);
   ans = (ans+mod-1)%mod;
   cout<<ans<<endl;
  */    
    
    
    //******************* iterative approach ***************************//
    vector<vector<int>> dpi(d, vector<int>(2));
    dpi[0][0]=1;
    for_(pos,len)
    {   vector<vector<int>> new_dpi(d, vector<int>(2));
        for_(rem,d)    
        {   for_(flag,2)
            {
                int range =(flag==1)?9:(k[pos]-'0');
                for_(i,range+1)
                    {   int newRem = (rem+i%d)%d;
                        int newFlag= ((!flag && (k[pos]-'0')>i )|| flag )? 1: 0;;
                        new_dpi[newRem][newFlag] = (new_dpi[newRem][newFlag]+
                        dpi[rem][flag])%mod;
                    }
                
            }
        }
        dpi=new_dpi;
    }
    
    int ans=(dpi[0][0]+dpi[0][1])%mod; ans= (ans+mod-1)%mod;
    cout<<ans<<endl;
    
}










/*
typedef struct structure{
    int x,y;
} pt;
pt p0;
bool cmp(pt a, pt b)
{
    return cw(p0,a,b);
}
bool cw(pt a, pt b, pt c){
    return ((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x))>=0
}



convex_hull(vector<pt>& points)
{
   // sort(points.begin(),points.end, cmp);// sorted according to y cordinate
    p0=points[0];
    sort(points.begin(),points.end, cmp);
    vector<pt> convexHull;
    stack<pt> temp;
    convexHull.push_back(points[0]);
    
    temp.push(points[0]);temp.push(points[1]);//temp.push(points[2]);
    pt top,top0;
    for(int it=2;it<points.size();++it)
    {   
        top=temp.top(); temp.pop(); top0=temp.top();
        pt next=points[it];
        if(cw(top0,top,next))
        {
            convexHull.push_back(top);
            temp.push(top);
            top0=top;
            top=next;
        }
        else
        {
          temp.push(next);  
        }
        
    }
    
}*/










