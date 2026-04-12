#include <iostream>
#include <vector>

using namespace std;

int main(){
        int n;
        cin >> n;

        vector<int> a;
        a.resize(n);

        for(int i = 0; i < n ; i++){
                cin >> a[i];
        }

        int c = 1;

        int max_val = max(a[0],a[1]);
        if(a[1] >= max_val){
                c++;
        }

        for(int i = 2 ; i < n; i++){
                max_val = max(max_val,a[i]);
                if(a[i] >= max_val){
                        c++;
                }
        }

        cout << c << endl;

}