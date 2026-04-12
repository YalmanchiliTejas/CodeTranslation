#include <bits/stdc++.h>
#define mp                    make_pair
#define pb                    push_back
#define ll                    long long
#define ss                       second
#define ff                        first
#define fr(i,a,b)   for(ll i=a;i<b;i++)
#define f(i,n)                fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n)                rf(i,n,0)
#define inf                  1000000007
#define eps         0.00000000000000001
#define endl                       '\n'

using namespace std;

int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};

vector<int> adj[300010];
vector<int> par(300010,-1);
vector<int> disco(300010,-1);
vector<int> finis(300010,-1);
vector<int> typ(300010,0);
vector<int> vis(300010,0);
vector<int> dis(300010,0);
vector<int> val;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //ofstream fout;
    //fin.open("input.txt");
    //fout.open("output.txt");
    int n,k;
    string s;
    cin>>n;
    cin>>s;
    cin>>k;
    char ch=s[k-1];
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=ch)
        {
            s[i]='*';
        }
    }
    cout<<s<<endl;
}

