#include<bits/stdc++.h>
using namespace std;
int h,w,cnt=0;
int main(){
	ios::sync_with_stdio(false);
    cin>>h>>w;
    for (int i=1;i<=h*w;i++){
        char data;
		cin>>data;
        if (data=='#')
                cnt++;
	}
    if (cnt==h+w-1)
        cout<<"Possible";
    else
        cout<<"Impossible";
    return 0;
}