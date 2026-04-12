#include <iostream>
#include <map>

using namespace std;

int main(){
        map<int,int> m;
        int i1,i2;
        char c;
        cin >> i1 >> c >> i2; 
        bool list[31];
        for(int i = 0; i < 31; i++) list[i] = false;
        while(i1){
                m.insert(make_pair(i1,i2));
                list[i2] = true;
                cin >> i1 >> c >> i2; 
        }   
        while(cin >> i1){
                int v = m.find(i1)->second;
                int n = 0;
                int idx = 30; 
                while(idx+1 && idx >= v){ 
                        if(list[idx]) n++;
                        idx--;
                }   
                cout << n << endl;
        }   
}