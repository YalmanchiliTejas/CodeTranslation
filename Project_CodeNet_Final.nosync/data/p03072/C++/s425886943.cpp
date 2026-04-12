#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,count = 0;
    cin >> n;
    vector<int>v(n);

    for(int i = 0;i < n;i++)
        cin >> v[i];
    
    for(int i = 0;i < n;i++){
        bool flag = true;
        for(int j = 0;j < i;j++){
            if(v[j] > v[i])flag = false;
        }
        if(flag)count++;
    }
        

    cout << count << endl;

    return 0;
}