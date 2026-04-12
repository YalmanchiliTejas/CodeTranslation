#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;
 
#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


int main(){
	int N; cin >> N;
	int H,ans=1,ma=0;
	cin >> H;
	ma=H;
	for(int i=1; i<N; i++){
		cin >> H;
		if(ma<=H){
			ma=H;
			ans+=1;
		}
	}
	cout << ans << endl;
	

}