#include<iostream>
#include<string>
#include<vector>
using ll = unsigned long long;
using namespace std;

int main(void) {
    int n;
    cin >> n;

    int* m = new int[n];
    for(int i =0; i< n;++i) {
        cin >> m[i];
    }

    int v = 1;

    for(int j=1; j<n; ++j){

        bool visible = true;

        for(int u=0; u<j; ++u){
            if(m[u]>m[j]) {
                visible = false;
                break;
            }
        }

        if(visible) {
            v++;
        }
    }

    cout << v << endl;

    return 0;
}