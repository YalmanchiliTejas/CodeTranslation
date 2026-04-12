#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;
            
int main(){

    vector<char> heaplist[100];
    
    int n = 0;
    cin >> n;
    
    while(true){
        string str;
        int p = 0;
        char c;
        
        cin >> str;
        if(str == "quit")break;
        else if(str == "push"){
            cin >> p;
            cin >> c;
            heaplist[p - 1].push_back(c);
        }else if(str == "pop"){
            cin >> p;
            cout << heaplist[p - 1].back() << endl;
            heaplist[p - 1].pop_back();
        }else if(str == "move"){
            int p2;
            cin >> p >> p2;
            heaplist[p2 - 1].push_back(heaplist[p - 1].back());
            heaplist[p - 1].pop_back();
        }
    }

    return 0;
}