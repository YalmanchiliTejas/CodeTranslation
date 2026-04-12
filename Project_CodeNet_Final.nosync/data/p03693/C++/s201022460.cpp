#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<list>
#include<map>
#include<iomanip>
#include<iostream>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int main(){
	int r,g,b,h;
	cin>>r>>g>>b;
	h=r*100+g*10+b;
	if(h%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
