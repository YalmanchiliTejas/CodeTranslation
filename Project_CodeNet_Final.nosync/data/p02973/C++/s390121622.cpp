#include<iostream>
#include<algorithm>
#include<vector>
//#include<set>
using namespace std;
int main()
{
	int i, n, left, right, mid;
	vector<long> data;
	vector<long>::iterator it;
	long input;

	cin >> n;
	cin >> input;
	data.push_back(input);
	for (i = 1; i < n; i++) {
		cin >> input;
		it = lower_bound(data.begin(), data.end(), input);
		if (it == data.begin() ){
			data.insert(it,input);
		}
		else {
			it--;
			if (*it == input ) {
					data.insert(it, input);

			}
			else {
				*it = input;
			}
		}
	}

	/*
	multiset<long,greater<long> > data;
	multiset<long,greater<long> >::iterator it;
	multiset<long,greater<long> >::iterator end;
	long input;
	long saitei;

	cin >> n;
	cin >> input;
	data.insert(input);
	for (i = 1; i < n; i++) {
		cin >> input;
		end = data.end();
		end--;
		saitei = *end;
		if (saitei >= input) {
			data.insert(input);
		}
		else {
			end++;
			for (it = data.begin(); it != end; it++) {
				if (*it < input) {
					data.erase(it);
					it = data.insert(input);
					break;
				}
			}
		}
		
		


	}

	*/


	cout << data.size() << endl;

	return 0;
}
