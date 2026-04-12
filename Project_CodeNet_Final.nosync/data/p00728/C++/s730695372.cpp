#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> vc;
    while(true){
        int n;cin>>n;
        if(n==0)break;
        int max,min;
        int sum=0;
        for(int i=0;i<n;i++){
            int score;cin >> score;
            if(i==0){
                min = score;
                max = score;
            }
            if(max < score)max = score;
            if(min > score)min = score;
            sum+=score;
        }
        sum -= max;
        sum -= min;
        int avg = sum/(n-2);
        cout << avg << endl;
    }
    return 0;
}

