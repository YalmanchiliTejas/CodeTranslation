#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <map>
#include <vector>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <algorithm>
#include <memory>
#include <memory.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int INF = 1 << 30;
const double EPS = 1e-10;
const double PI = 3.14159;

int main(){
	int n;
	while(cin >> n && n){
		int w_count = 0;
		int b_count = 0;
		stack<int> w, b;
		for(int i = 0; i < n; i++){
			int go;
			cin >> go;
			if(i % 2 == 0){
				if(go == 1){
					w_count++;
					if(w.empty()) w.push(i);
					else{
						int lw = w.top();
						if(lw == i-1) w.pop();
						w.push(i);
					}
				}else{
					b_count++;
					if(b.empty()) b.push(i);
					else{
						int lb = b.top();
						if(lb == i-1) b.pop();
						b.push(i);
					}
				}
			}else{
				if(go == 0){
					if(b.empty()){
						w.pop();
						w_count -= i;
						b_count += i+1;
						b.push(i);
					}else{
						int lb = b.top();
						if(lb == i-1){
							b_count++;
							b.pop();
							b.push(i);
						}else{
							w.pop();
							b.pop();
							b_count += i - lb;
							w_count -= i - lb - 1;
							b.push(i);
						}
					}
				}else{
					if(w.empty()){
						b.pop();
						b_count -= i;
						w_count += i+1;
						w.push(i);
					}else{
						int lw = w.top();
						if(lw == i-1){
							w_count++;
							w.pop();
							w.push(i);
						}else{
							w.pop();
							b.pop();
							w_count += i - lw;
							b_count -= i - lw - 1;
							w.push(i);
						}
					}
				}
			}
		}
		cout << b_count << endl;
	}
	return 0;
}