#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int a;
    vector<int> vec;
    
    
    cin >> a;
    
    
    for(int i = 0; i < a; ++i){
        int b;
        cin >> b;
        vec.push_back(b);
    }
    
    int count = 0;
    int hight = 0;
    
    for(int value : vec){
        if(value >= hight){
            ++count;
            hight = value;
            
        }
            
    }
    
    printf("%d", count);
    
    
    return 0;
}
