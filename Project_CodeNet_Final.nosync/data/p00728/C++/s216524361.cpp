#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;

    while(cin >> n, n != 0){
        vector<int> s;
        for(int i=1; i<=n; i++){
            int tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        sort(s.begin(), s.end());


        s.at(0) = 0;
        s.at(s.size()-1) = 0;

        vector<int>::iterator it = s.begin();
        int sum = 0;
        while(it != s.end()){
            sum += *it;
            it++;
        }
        cout << sum / (s.size()-2) << endl;
    }
    return 0;
}