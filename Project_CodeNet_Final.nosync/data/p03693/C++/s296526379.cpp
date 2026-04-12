#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
 
using namespace std; 

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

int main(){

    int a,b,c;
    cin>>a>>b>>c;
    a*=100;
    a+=b*10;
    a+=c;

    if(a%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

	return 0;
}
