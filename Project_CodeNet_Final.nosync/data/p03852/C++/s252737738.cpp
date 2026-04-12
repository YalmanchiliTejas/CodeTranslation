#include<bits/stdc++.h>
using  namespace  std;

#define all(p) p.begin(), p.end()
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define ll long long
#define llu unsigned long long
#define ld long double
#define vll vector<long long int>
#define vi vector<int>
#define pii pair <int, int>
#define pll pair <long long int, long long int>
#define vpii vector<pair<int,int> >
#define nl cout<<"\n"
#define sp cout<<" "
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const  int  INF = 0x7f7f7f7f;

int  main ()
{
	ios_base::sync_with_stdio(false);
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
	char c;
	cin>>c;
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		cout<<"vowel\n";
	else cout<<"consonant\n";
    return  0;
}
