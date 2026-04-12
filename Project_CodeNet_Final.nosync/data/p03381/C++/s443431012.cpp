#include<bits/stdc++.h>
using namespace std;
int tab[200005];
int a;
vector<int> dosort;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a;
	for (int i=0;i<a;i++){
		cin >> tab[i];
		dosort.push_back(tab[i]);
	}
	sort(dosort.begin(),dosort.end());
	vector<int>::iterator low;
	//dosort.push_back(0);
	//low=lower_bound(dosort.begin(), dosort.end(), tab[i]);
	for (int i=0;i<a;i++){
		//low=lower_bound(dosort.begin(), dosort.end(), tab[i]);
		if(tab[i] > dosort[a/2-1]){
			cout << dosort[a/2-1]<<endl;
		}
		else cout << dosort[a/2]<<endl;
		
	}
	return 0;
}