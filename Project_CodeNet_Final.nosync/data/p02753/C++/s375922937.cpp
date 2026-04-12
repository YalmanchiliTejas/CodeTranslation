#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
#define inf 0x3f3f3f3f
using namespace std;
int a[1000005];
int main()
{
    char s[4];
    int w=0; 
    cin>>s;
    if(s[1]!=s[0])w=1;
    if(s[2]!=s[1])w=1;
    if(w==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
 } 