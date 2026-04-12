#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;


	int s;

	int sum,ave;

	int i;

	while(1){
		vector<int> v;
		sum = 0;

		cin >> n;
		if (n==0) break;

		for(i=0;i<n;i++){
			cin >> s;
			v.push_back(s);
		}

		
		sort(v.begin(),v.end());

		for(i=1;i<v.size()-1;i++){
			sum += v[i];
		}

		ave = sum/(v.size()-2);

		cout << ave << endl;

	}
	return 0;
}