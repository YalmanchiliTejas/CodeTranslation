#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string s;
    int nagasa;
    int judge=0;
    
    cin >> s;
    nagasa=s.size()-1;
    
    for(int i=0;i<nagasa;i++){
        if(s[i]=='A' && s[i+1]=='C'){
            judge=1;
            break;
        }
    }
    
    if(judge==1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    
    return 0;
}
