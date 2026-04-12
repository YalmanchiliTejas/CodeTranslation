#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canGoal(vector<int> &v){
    int l = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(i>l){
            return false;
        }
        l = max(l,i+v[i]);
    }
    return true;
}
int main(){
    int a;
    cin >> a;
    vector<int> vec(a);
    for (size_t i = 0; i < a; i++)
    {
        cin >> vec[i];
        vec[i]/=10;
    }
    bool result = 1;
    if(!canGoal(vec))result = false;
    reverse(vec.begin(),vec.end());
    if(!canGoal(vec))result = false;
    
    cout << (result ? "yes":"no") << endl;
    return 0;
}
