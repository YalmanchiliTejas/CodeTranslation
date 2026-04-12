#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(void){
	int m,n;

	while(cin>>m>>n && (m||n)){
		vector<int> v;
		for(int i=1;i<=m;i++) v.push_back(i);
		int now = 0;
		for(int i=1;i<=n;i++,now=(now+1)%v.size()){
			stringstream ss;
			if(i % 3 == 0) ss<<"Fizz";
			if(i % 5 == 0) ss<<"Buzz";
			if(ss.str() == "") ss<<i;
			string s1 = ss.str();

			string s2;
			cin>>s2;

			if(s1 != s2 && v.size() > 1){
				v.erase(v.begin() + now);
				now--;
			}
		}

		cout<<v[0];
		for(int i=1;i<v.size();i++) cout<<" "<<v[i];
		cout<<endl;
	}

	return 0;
}