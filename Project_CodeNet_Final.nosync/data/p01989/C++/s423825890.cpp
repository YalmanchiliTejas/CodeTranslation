#include<bits/stdc++.h>

using namespace std;

int main(){

  string s;
  int sum = 0;
  
  cin >> s;

  for(int i = 1;i < s.size() - 2;++i){
	for(int j = i + 1;j < s.size() - 1;++j){
	  for(int k = j + 1;k < s.size();++k){
		vector<string> ss(4);
		vector<int> mm(4);
		bool flag = true;

		  for(int m = 0;m < i;++m)
			ss[0].push_back(s[m]);
		  for(int m = i;m < j;++m)
			ss[1].push_back(s[m]);
		  for(int m = j;m < k;++m)
			ss[2].push_back(s[m]);
		  for(int m = k;m < s.size();++m)
			ss[3].push_back(s[m]);

		  for(int m = 0;m < 4;++m){
			if(ss[m].size() >= 2){
			  if(ss[m][0] == '0'){
				flag = false;
			  }
			}
		  }

		  if(flag == false)
			continue;
		  
		  //cout << ss[0] << "." << ss[1] << "." << ss[2] << "." << ss[3] << endl;

		  for(int m = 0;m < 4;++m)
			mm[m] = atoi(ss[m].c_str());

		  //cout << mm[0] << "." << mm[1] << "." << mm[2] << "." << mm[3] << endl;

		  if(mm[0] < 0 || mm[0] > 255 ||mm[1] < 0 || mm[1] > 255 ||
			 mm[2] < 0 || mm[2] > 255 ||mm[3] < 0 || mm[3] > 255 )
			continue;

		  else
			sum++;
		  
	  }
	}
  }

  cout << sum << endl;
  
}
