#include <cstdlib>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int N;
  	int cnt=1;
    cin >> N;
    string tmp1,tmp2;
    string buf;
    vector<string> H;
    string s[N+1];
    for(int i=0; i<N+1; ++i) {
        getline(cin,s[i]);
        stringstream ss{s[i]};
        while (getline(ss, buf, ' ')) {
            H.push_back(buf);
	    }
    }
    int max=0;
  	for(int i=0; i<N-1; ++i) {
      tmp1=H[i];
      tmp2=H[i+1];
      if(max<=stoi(tmp1)) max=stoi(tmp1);
      if(stoi(tmp1)<=stoi(tmp2)) {
        if(max<=stoi(tmp2)) {
            ++cnt;
            max=stoi(tmp2);
        }
      }
    }
  	cout << cnt << "\n";
    return 0;
}