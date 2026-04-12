#include <bits/stdc++.h>
#include <time.h>
#include <assert.h>


using namespace std;



#define For(i,x,n)  for(long long i=x;i<n;i++)
#define rFor(i,x,n) for(long long i=x;i>=n;i--)
#define itFor(it,st)   for(auto it=st.begin() ; it!=st.end() ; it++)
#define MOD 1000000007
#define PI 3.141592653589793
#define INF 999999999999999999
#define N 1000005
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sp " "
#define cont continue
#define brk break

#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed;
    cout<<setprecision(3);
    srand(time(NULL));

    string s;
    cin>>s;
    bool ca=false,cb=false;
    For(i,0,3)
    	if(s[i]=='A')
    		ca = true;
    	else
    		cb = true;
    if(ca and cb)
    	cout<<"Yes";
    else
    	cout<<"No";

    //cout<<"\nTime used = "<<static_cast<double>(clock())/(CLOCKS_PER_SEC)<<"s"<<endl;  // - for checking time used for a test case
    return 0;
}

//s1.substr(1,3) - return 3 characters starting from position 1 as substring of string sz1. eg sz1="shreynumh" sz1.substr(2,5)="reyan"
//num = atoi(s.c_str()); //convert string s to integer num
//n.erase(i,std::string::npos); //erase i th position in string n , decreasing string size
//s.find(b)!= std::string::npos - finds string b in string a - true if found
//cout<<"Time used = "<<static_cast<double>(clock())/(CLOCKS_PER_SEC)<<"s"<<endl;  // - for checking time used for a test case                
