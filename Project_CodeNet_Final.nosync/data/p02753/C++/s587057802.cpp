#include"bits/stdc++.h" 
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
typedef long long int ll;
vector<int>u;
vector<int>w;
vector<int>::iterator it;
priority_queue<int>pq;
const int N=1e5+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == 'A')
		{
			a++;
		}
		else if(s[i] == 'B')
		{
			b++;
		}
	}
	if(a == 3 or b == 3)
	{
		cout<<"No";
		return 0;
	}

	cout<<"Yes";
	return 0;
}