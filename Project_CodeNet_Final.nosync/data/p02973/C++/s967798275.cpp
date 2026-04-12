// Author -> Preeyadarshee Dev
//
// train hard win easy :D
// nik is love
// nik is motivation
//
// do modulo operations very carefully
// try to avoid binary search, use linear search preferrably to make calculations easier
// always make your custom binary search and watch out for overflows
// read the problems carefully
// never rely on floating point calculation
#include <bits/stdc++.h>
#define mp                    make_pair
#define pb                    push_back
#define ll                   long long
#define ss                       second
#define ff                        first
#define fr(i,a,b)   for(ll i=a;i<b;i++)
#define f(i,n)                fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n)                rf(i,n,0) 
#define inf                   1000000007
#define eps                  0.000000000000001
#define endl                       '\n'
#define sz(a)                int((a).size())
#define all(c)               (c).begin(),(c).end()
#define tr(c,i)              for(typeof(c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)         ((c).find(x) != (c).end())
#define cpresent(c,x)        (find(all(c),x) != (c).end())
#define pi                   pair<int,int>
#define pll                  pair < ll , ll >
#define PI                   3.141592653589793238462643383279502884197169399375105820974944592307816406286
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef vector< int > vi;
typedef vector< vi > vvi;
int dx[8]={-2,-2,1,-1,-1,-1,1,1};
int dy[8]={1,-1,-2,-2,-1,1,-1,1};
vector<int> adj[100010],dis(100010,inf),par(100010,0);
vector<vector<int>> vis(15,vector<int> (15,0)),state(15,vector<int> (15,0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //ofstream fout;
    //fin.open("input.txt");
    //fout.open("output.txt");
    multiset<pair<int,int>>mt;
    int n;
    cin>>n;
    vector<int> v(n);
    f(i,n)
    {
        cin>>v[i];
    }
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        mt.insert({v[i],-1});
        auto itr=mt.find({v[i],-1});
        if(itr==mt.begin())
        {
            mt.erase(itr);
            mt.insert({v[i],cnt++});
        }
        else
        {
            auto itk=itr;
            itr--;
            mt.erase(itk);
            mt.insert({v[i],itr->ss});
            mt.erase(itr);
        }
    }
    cout<<cnt-1<<endl;
}
