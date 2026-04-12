#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> a;

    for(int i=0; i<n; i++){
        int input_a;
        cin >> input_a;
        if (i % 2 == 0) a.push_back(input_a);
        else a.insert(a.begin(),input_a);
    }

    if (n %2 == 1)reverse(a.begin(), a.end());

    ostringstream ss;

    for(int i=0; i<n; i++){
        if(i!=0) ss << " ";
        ss << a[i];
    }

    cout << ss.str();

    return 0;
}