#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdlib>
#include <set>

using namespace std;
 
int main(void){

    string S;
    set<char> string_set;
    
    cin >> S;

    for(int i =0; i <3; i++){
        string_set.insert(S[i]);
    }

    if(string_set.size() > 1){
        cout << "Yes";

        return 0;
    } 

    cout << "No";




    return 0;
}