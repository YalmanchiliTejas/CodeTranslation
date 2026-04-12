#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define  fill(st,et,val,arr) for(int i=st;i<=et;i++)arr[i]=val;
#define all(v) v.begin(),v.end()
template <class T>
inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch)) w = ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}
 
const int M=1e9 + 7;
const int MAX=1e5+7;
using namespace std;
bool comp(int a,int b)
{	
	return a>b;
}
void printQ(vector<int> q)
{   
    cout<<"v->  ";
	for(int i=0;i<q.size();i++)
	{
		cout<<q[i]<<" ";
	}
	cout<<endl;
}
int cel(int d,int n)
{
	int ans=d/(n+1);
	if((d%(n+1))!=0)ans++;
	return ans;
}
int32_t main() 
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==m)
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;
	return 0;
}











