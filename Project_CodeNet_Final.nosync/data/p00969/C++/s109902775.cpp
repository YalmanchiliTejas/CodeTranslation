#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using Int = int;

int main(){
	Int n;
	std::cin >> n;
	std::vector<Int> v(n);
	for(Int &i : v) std::cin >> i;
	std::sort(v.begin(), v.end());
	std::vector<std::pair<Int, Int>> a(n * (n - 1) / 2);
	for(int i = 0; i < n; ++i) for(int j = 0; j < i; ++j){
		a[i * (i - 1) / 2 + j].first = v[i] - v[j];
		a[i * (i - 1) / 2 + j].second = v[j];
	}
	std::sort(a.begin(), a.end(), [](std::pair<Int, Int> &l, std::pair<Int, Int> &r){
		if(l.first < r.first) return true;
		else if(l.first == r.first){
			Int lr = l.second % r.first;
			Int rr = r.second % r.first;
			if(lr < rr) return true;
			else if(lr == rr) return l.second < r.second;
			else return false;
		}
		else return false;
	});
	
	std::cout << [&a](){
	//	for(auto i : a) std::cout << i.first << ',' << i.second << std::endl;
		std::pair<Int, Int> prev(0, 0);
		Int cnt = 0;
		Int max = 0;
		for(auto i : a){
			if(i.first == prev.first && i.second == prev.first + prev.second){
				++cnt;
				if(max < cnt) max = cnt;
			}else{
				cnt = 0;
			}
			prev = i;
		}
		return max + 2;
	}() << std::endl;
}

