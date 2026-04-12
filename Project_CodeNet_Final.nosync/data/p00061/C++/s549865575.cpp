#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
 
#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif
 
int main(){
	std::vector<std::pair<int, int> > data;
	std::vector<int> rank;
	int r = 0;
	int pre_s = -1;
	int p, s, q;
	char tmp;


#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
	//FILE *fp = fopen("test.txt", "r");
#endif

#if INPUT_FROM_FILE
	while(ifs >> p >> tmp >> s){
#else
	while(std::cin >> p >> tmp >> s){
#endif
		if(p == 0 && s == 0){
			break;
		}
		data.push_back(std::pair<int, int>(s, p));
	}
 
	std::sort(data.begin(), data.end());
	std::reverse(data.begin(), data.end());

	rank.resize(data.size(), 0);
	for(int i = 0; i < data.size(); i++){
		if(pre_s != data[i].first){
			r++;
		}
		rank[i] = r;
		pre_s = data[i].first;
	}
 
#if INPUT_FROM_FILE
	while(ifs >> q){
#else
	while(std::cin >> q){
#endif
		for(int i = 0; i < data.size(); i++){
			if(data[i].second == q){
				std::cout << rank[i] << std::endl;
			}
		}
	}

#if INPUT_FROM_FILE
	//fclose(fp);
#endif
    return 0;
}
