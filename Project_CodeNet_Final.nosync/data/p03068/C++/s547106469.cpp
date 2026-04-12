#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// 上 左 下 右
const int N=100005,M=1000005,mod=1000000007;
const long long llinf=9223372036854775807ll;
int n,k;
string s;
int main(){
	cin>>n>>s>>k;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[k-1])
			cout<<'*';
		else
			cout<<s[i];
	}
	return 0;
}