#include <iostream>
using namespace std;
int main(void){
    int N = 0;
    int maxHight = 0;
    int canSee = 0;
    cin >> N;
    for(int i = 0;i < N;i++){
        int x;
        cin >> x;
        
        if(maxHight <= x){
            canSee++;
            maxHight = x;
        }
    }
    cout << canSee << endl;
    return 0;
}
