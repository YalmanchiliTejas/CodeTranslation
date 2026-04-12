#include<bits/stdc++.h>
using namespace std;
#define lli long long int
 int main()
{	
lli n,i,j,flag=0;
string s;
cin >> s;
for(i=0;i<s.size()-1;i++){
	if(s[i]!=s[i+1]){
		flag=1;
		break;
	}
}
if(flag==0)cout << "No" <<'\n';
else cout << "Yes"<< '\n';

return 0;}
