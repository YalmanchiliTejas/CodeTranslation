#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

int max_index(std::vector<long> &c1){
    std::vector<long>::iterator iter1 = std::max_element(c1.begin(), c1.end());
    int index1 = std::distance(c1.begin(), iter1);
    return index1;
}

long long calc(std::deque<long> &a){
	int n = a.size();
	std::deque<long> b(2);
	b[0] = a.front();	a.pop_front();
	b[1] = a.back();	a.pop_back();
	long long v = std::abs(b[0] - b[1]);

	while( !a.empty() ){
		std::vector<long> t(4);
		t[0] = std::abs(a.front() - b.front());
		t[1] = std::abs(a.front() - b.back());
		t[2] = std::abs(a.back() - b.front());
		t[3] = std::abs(a.back() - b.back());
		int ts = max_index(t);
		switch(ts){
		case 0:
			v += std::abs( b.front() - a.front() );
			b.push_front(a.front());
			a.pop_front();
			break;
		case 1:
			v += std::abs( b.back() - a.front() );
			b.push_back(a.front());
			a.pop_front();
			break;
		case 2:
			v += std::abs( b.front() - a.back() );
			b.push_front(a.back());
			a.pop_back();
			break;
		case 3:
			v += std::abs( b.back() - a.back() );
			b.push_back(a.back());
			a.pop_back();
			break;
		}
	}
	return v;
}



int main(){
	int n;
	std::cin >> n;
	std::deque<long> a(n);
	long tmp;
	for(int i=0; i<n; i++){
		std::cin >> tmp;
		a[i] = tmp;
	}
	std::sort(a.begin(), a.end());

	long long v = calc(a);
	std::cout << v <<std::endl;
	return 0;
}
