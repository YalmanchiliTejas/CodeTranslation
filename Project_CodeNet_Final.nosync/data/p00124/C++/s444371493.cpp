#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <functional>

using namespace std;

bool cmp(pair<int,string> a , pair<int,string> b){  
	return a.first > b.first; 
} 

int main(void){
	bool b=false;
	while(1){
		int a,n;
		string s;
		vector< pair<int,string> > P;
		int w,d,l;
		cin >> n;
		if(n==0)break;
		if(b==true)cout << endl;
		b=true;
		for(a=0;a<n;a++){
			 cin >> s >> w >> l >> d; 
			P.push_back(make_pair(w*3+d,s));
		}
		stable_sort(P.begin(),P.end(),cmp);
		for(a=0;a<n;a++){
			cout << P[a].second << "," << P[a].first << endl; 
		}
	}
	return 0;
}