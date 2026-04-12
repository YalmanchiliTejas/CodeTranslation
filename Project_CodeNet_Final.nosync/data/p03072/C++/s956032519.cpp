#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> mountains;
    for(int i=0; i<N; ++i){
        int tmp;
        cin >> tmp;
        mountains.push_back(tmp);
    }
    int highest = 0;
    int count = 0;
    for(auto m : mountains){
        if(m>=highest){
            ++count;
            highest = m;
        }
    }
    cout << count << endl;
}
