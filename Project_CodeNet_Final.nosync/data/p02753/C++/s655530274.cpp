#include <bits/stdc++.h>
#include<iterator>
#include<vector>
#include<algorithm>


#define v vector
#define ll long long 
#define vpll vector<pair<long long,long long> > 
#define F first
#define S second
#define mp make_pair
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pci pair<char,int>
#define un unsigned

#define mod 1000000007
#define MAXN 100000
using namespace std; 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main() 
{ 
    string s;
    cin>>s;
    int a_count = 0;
    int b_count = 0;
    for(int i = 0 ; i <3 ; i++)
    {
        if(s[i] == 'A')
        a_count++;
        else
        b_count++;
    }
    if(a_count*b_count)
    cout<<"Yes";
    else
    cout<<"No";
    return 0;    

}