#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF (1<<21)

bool cmp(pair<int,string> a , pair<int,string> b){
	return a.first > b.first;
}
int main(){
	int n,c=0;
	while(cin >> n,n){
		if(c++)cout << endl;
		vector< pair<int,string> >data; 
		rep(i,n){
			int a,b,c;
			string s;
			cin >> s >>  a >> b >> c;
			data.push_back(make_pair(a*3+c,s));
		}
		stable_sort(data.begin(),data.end(),cmp);
		rep(i,n)
			cout << data[i].second << "," << data[i].first << endl;
	}
}