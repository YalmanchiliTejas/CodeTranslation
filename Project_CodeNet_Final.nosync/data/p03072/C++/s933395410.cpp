#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,count;
    count = 1;
    cin >>a;
    vector<int> mvec(a);
    vector<int> vec(a);
    for (int i = 0; i < a; i++) {
        cin >> vec.at(i);
        mvec.at(i) = *std::max_element(vec.begin() ,vec.end());
	}
    for(int i=1;i<a;i++){
        if(vec.at(i)>=mvec.at(i))
            count++;
    }
    cout<<count<<endl;
}
