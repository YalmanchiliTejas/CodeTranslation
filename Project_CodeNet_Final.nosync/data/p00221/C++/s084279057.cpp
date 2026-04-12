#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
using namespace std;

int main()
{
    int n,m;
    while(cin >> m >> n, m || n){
        set<int> t;
        for(int i = 0; i < m; ++i) t.insert(i+1);
        
        set<int>::iterator it = t.begin();
        for(int i = 1; i <= n; ++i){
            string s;
            cin >> s;
            if(t.size() != 1){
            if(i % 3 == 0 && i % 5 == 0){
                if(s != "FizzBuzz"){
                    t.erase(it++);
                }
                else {
                    it++;
                }
            } else if(i % 3 == 0){
                if(s != "Fizz"){
                    t.erase(it++);
                } else {
                    it++;
                }
            }  else if(i % 5 == 0){
                if(s != "Buzz"){
                    t.erase(it++);
                }
                else {
                    it++;
                }
            } else if(i != atoi(s.c_str())){
                t.erase(it++);
            } else {
                it++;
            }
            if(it == t.end()){
                it = t.begin();
            }
            }
        }
        
        for(it = t.begin(); it != t.end(); ++it){
            if(it != t.begin()) cout << ' ';
            cout << *it;
        }
        cout << endl;
    }
}