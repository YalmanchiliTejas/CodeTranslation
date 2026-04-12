#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
 
using namespace std;

int main()
{
    string left = "qwertasdfgzxcvb";
    string right = "yuiophjklnm";
    string input;
    while(1){
        cin >> input;
        if(input == "#") break;
        int beforehand = 1;
        // nowhand = 0/right, 1/left
        for(int j = 0; j < right.length(); j++){
                if(right[j] == input[0]){
                    beforehand = 0;
                    break;
                }
            }
        int cnt = 0;
        for(int i = 0; i < input.length(); i++){
            int nowhand = 1;
            for(int j = 0; j < right.length(); j++){
                if(right[j] == input[i]){
                    nowhand = 0;
                    break;
                }
            }
            if(beforehand != nowhand){
                cnt++;
                beforehand = nowhand;
            }
        }
        cout << cnt << endl;    
    }
}