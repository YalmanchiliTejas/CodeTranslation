//**************************
//*** writer  :  Alan Hu **
//************************

//傅思程你敢抄我程序？？？ 
//傅思程你敢抄我程序？？？	                
//傅思程你敢抄我程序？？？ 

#include<bits/stdc++.h>

using namespace std;
     
#define CLEAN(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define pb push_back
#define rept(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
     
int n,m,w,pos;
string s[110];
bool com=true,col[110][2],row[110][2],vis[110][110];
vector <string> ans;
     
int main()
{
    cin>>n>>m;
    rept(i,0,n) cin>>s[i];
    rept(i,0,n)
    {
    	rept(j,0,m)
    	{
    		if(vis[i][j]) continue;
    		if(s[i][j]=='.')
    		{
    			row[i][0]=true;
    			col[j][0]=true;
    		}
    		else
    		{
    			row[i][1]=true;
    			col[j][1]=true;
    		}
    	}
    }
    rept(i,0,n)
    {
    	if(row[i][0]&& !row[i][1])
    	{
    		com=true;
    		rept(j,0,m) vis[i][j]=true;
    	}
    }
    rept(i,0,m)
    {
    	if(col[i][0]&& !col[i][1])
    	{
    		com=true;
    		rept(j,0,n) vis[j][i]=true;
    	}
    }
    rept(i,0,n)
    {
    	string tmp="";
    	rept(j,0,m) if(!vis[i][j]) tmp.pb(s[i][j]);
    	if(tmp.size()>0) ans.pb(tmp);
    }
    rept(i,0,ans.size())
    {
    	printf("%s\n",ans[i].c_str());
    }
    	return 0;
}