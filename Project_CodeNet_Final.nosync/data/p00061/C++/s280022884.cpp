#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
	int a,b;
	char c;
	map <int,int>x;
	set <int> y;
	while (1){
		cin>>a>>c>>b;
		if (a==0&&b==0) break;
		x[a]=b;
		y.insert(b);
	}
	while (cin>>a){
		b=1;
		set<int>::reverse_iterator it=y.rbegin();
		while (*it!=x[a]){
			it++;
			b++;
		}
		cout<<b<<endl;
	}
}