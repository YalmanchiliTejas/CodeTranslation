#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
int main(void){

    int n;
    cin >> n;
    
    vector<int> data;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
    
    int result = 1;
    int max = data[0];

    for(int i=1; i<data.size(); i++) {
        if(data[i]>=max) {
            result++;
            max = data[i];
        }
    }
    
    cout << result << endl;

    return 0;

}
