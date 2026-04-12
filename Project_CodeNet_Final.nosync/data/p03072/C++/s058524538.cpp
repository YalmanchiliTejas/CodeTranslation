#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define ll long long int
#define ull unsigned long long int

#define INF 100000000000L

using namespace std;

int main(){
    int N;
    cin >> N;
    int count = 0;
    int max = 0;
    for(int i=0;i<N;i++){
        int H;
        cin >> H;
        if(max > H) continue;
        else{
            max = H;
            count++;
        }
    }
    cout << count << endl;
    return 0;

}