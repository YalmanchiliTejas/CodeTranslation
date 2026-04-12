#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, o = 1;
    vector<int> v;
    cin >> n;
	int h;
    cin >> h;
    v.push_back(h);
    n--;
    while(n--){
    	int hi;
    	cin >> hi;
    	if(hi >= *max_element(v.begin(), v.end())) o++;
    	v.push_back(hi);
    }
    cout << o << endl;
}