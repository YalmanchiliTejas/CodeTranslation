#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int m,i,k,n,flag=0;
	string s,t,temp;
	cin>>s;
	int cnt1=0,cnt2=0;
	for(i=0;i<3;i++){
        if(s[i]=='A'){
            cnt1++;

        }
        else{
            cnt2++;
        }
	}
	if(min(cnt1,cnt2)!=0){
        cout<<"Yes";
	}
	else{
        cout<<"No";
	}


	return 0;
}
