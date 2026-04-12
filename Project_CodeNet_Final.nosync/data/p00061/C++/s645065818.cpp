#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
	int a,b,i;
	char c;
	vector<int>x,y;
	while (1){
		cin>>a>>c>>b;
		if (a==0&&b==0) break;
		x.push_back(a);
		y.push_back(b);
	}
	set<int> z(y.begin(),y.end());
	while (cin>>a){
		for (i=0;i<(int)x.size();i++){
			if (x[i]==a) break;
		}
		b=1;
		set<int>::reverse_iterator it=z.rbegin();
		while (*it!=y[i]){
			it++;
			b++;
		}
		cout<<b<<endl;
	}
}