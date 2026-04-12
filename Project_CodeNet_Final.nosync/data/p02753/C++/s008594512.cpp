#include <iostream>
using namespace std;


int main()
{
    char s[3];
    int i, j;

    for(i=0;i<3;i++){
        cin >> s[i];
    }

    j = 0;
    for(i=0;i<3;i++){
        if(s[i] == 'A'){
            j++;
        }
    }

    if(j==0 || j==3){
        cout << "No";
    }else{
        cout << "Yes";
    }

    return 0;
}