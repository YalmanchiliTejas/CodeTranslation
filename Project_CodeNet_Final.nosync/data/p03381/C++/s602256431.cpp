#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main(){
	
	int N;
	cin >> N;
	vector<int> vec(N);
	vector<int> sorted(N);
	
	int bottom,upper;
	
	for(int i=0; i<N; i++){
		cin >> vec.at(i);
	}
	sorted = vec;
	
	std::sort(sorted.begin(), sorted.end());
	
	bottom = sorted.at(N/2 -1);
	upper = sorted.at(N/2);
	
	/*cout << bottom << " " << N/2 << endl;
	cout << upper << " " << N/2 +1 << endl;
	
	for(int i=0; i<N; i++){
		cout << vec.at(i) << " " ;
	}
	cout << endl;
	for(int i=0; i<N; i++){
		cout << sorted.at(i) << " " ;
	}
	cout << endl;
	*/
	for(int i=0; i<N; i++){
		
		if(vec.at(i)<=bottom) cout  << upper <<endl;
		else if(vec.at(i)>=upper ) cout << bottom<< endl;
		else cout << "problem" << endl;
	}
	
}
