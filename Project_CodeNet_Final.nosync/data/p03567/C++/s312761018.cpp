#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define MAX 1e16
#define SIZE 1e8
#define mod 1000000007
#include<regex>


using namespace std;




int main()
{
	string str;
	cin>>str;
	regex r(".*AC.*");
	if(regex_match(str,r)){
	    cout<<"Yes"<<endl;
	}else{
	    cout<<"No"<<endl;
	}
}