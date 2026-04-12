#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num;
    vector<int>ans;
    
    for(int i = 0;i < n;i++){
        cin >> num;
        if(i%2 == 0){
            ans.push_back(num);
        }else{
            ans.insert(ans.begin(),num);
        }
    }
    

    int check = (int)ans.size();
    if((check % 2) == 0){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i != ans.size()-1){
                cout << " ";
            }
        }
    }else{
        for(int i = check-1; i >= 0; i--){
            cout << ans[i];
            if(i != 0){
                cout << " ";
            }
        }
    }
    
    cout << "\n";
    return 0;
}