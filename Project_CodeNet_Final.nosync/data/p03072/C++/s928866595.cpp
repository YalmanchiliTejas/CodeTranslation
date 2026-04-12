#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int counter = 0;

    for(size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int h_max = 0;
    for(size_t i = 0; i < v.size(); i++)
    {
        if(h_max <= v[i]){
            counter ++;
            h_max = v[i];
        }
    }
    cout << counter << endl;
    


    return 0;
}