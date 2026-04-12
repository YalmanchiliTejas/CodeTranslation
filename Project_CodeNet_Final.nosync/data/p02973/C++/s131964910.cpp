#include<bits/stdc++.h>

#define range 100005
#define mod 1000000007
#define eps 1e-9
#define PI 3.14159265358979323846
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define _ <<" "<<

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair <int, int> ii;
typedef pair<int, pair<int,int> > iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	multiset<int> mult;
	mult.insert(a[0]);
	for(int i=1;i<n;i++)
	{
		auto it = mult.lower_bound(a[i]);
		if(it!=mult.begin())
		{
			it--;
			mult.erase(it);
		}
		mult.insert(a[i]); 
	}
	cout<<mult.size();
	return 0;
}