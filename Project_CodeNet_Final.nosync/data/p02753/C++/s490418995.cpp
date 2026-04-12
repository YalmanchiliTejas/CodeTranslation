#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main(){
	char x,y,z;
	cin>>x>>y>>z;
	ll s=0;
	if(x=='A'||y=='A'||z=='A')
		s++;
	if(x=='B'||y=='B'||z=='B')
		s++;
	if(s==2)
		cout<<"Yes";
	else
		cout<<"No";
}
