#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(void){
    // Your code here!
    int N;
    cin >> N;
    vector<vector<char>> ss;

    string  str = "abcdefghijklmnopqrstuvwxyz";
    vector<char> uniques(str.begin(), str.end());
    
    
    for(int i =0; i < N; i++){
        string tmp;
        cin >> tmp;
        vector<char> s(tmp.begin(), tmp.end());
        ss.push_back(s);
        sort(s.begin(),s.end());
        unique(s.begin(), s.end());
        vector<char> buff;
        set_intersection(uniques.begin(), uniques.end(),s.begin(), s.end(), inserter( buff, buff.end()) );
        uniques = buff;
    }
    
    sort(uniques.begin(), uniques.end());

    
    for(auto it = uniques.begin(); it != uniques.end(); ++it){
        int min = 100000000000;
        for(int i =0; i < ss.size() ;i++){
            int num = count(ss[i].begin(), ss[i].end(), *it);
            if(num < min){
                min = num;
            }
        }
        for(int i = 0; i < min; i++){
            cout << *it;
        }
    }
    cout << endl;    

    
}
