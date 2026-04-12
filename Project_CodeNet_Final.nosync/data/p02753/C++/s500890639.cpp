
#include<bits/stdc++.h>
using namespace std;
/**
********************************************************************
******************* Author:Bisnu sarkar ****************************
********************************************************************
**/
#define ull            unsigned long long
#define ll             long long
#define pii            pair<int,int>
#define sit            set<int> :: iterator
#define vrit           vector<int> :: reverse iterator
#define ff             first
#define ss             second
#define endl           '\n';
#define sz(s)          (int)s.size()
#define all(s)         s.begin(),s.end()

int set_1(int n,int pos){return n = (n | (1<<pos));}
int reset_0(int n,int pos){return n= n & ~(1<<pos);}
bool check_bit(int n,int pos){return n = n & (1<<pos);}

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);
const double eps=1e-9;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t=1,te=0;
    // cin>>t;
    while(t--){
        string s;
        cin>>s;

        set<char>ss;

        for(int i=0;s[i];++i)ss.insert(s[i]);

        if(ss.size()>=2){
            printf("Yes\n");
        }    
        else{
            printf("No\n");
        }   


        //printf("Case %d: ",++te);
    }
    return 0;
}