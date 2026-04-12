#include <iostream>
using namespace std;

int main()
{
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    char c;
    cin >> c;
    
    int con = 0;
    for(int i = 0; i < 5; i++){
        if(v[i] == c){
            cout << "vowel" << endl;
            con++;
            break;
        }
    }
    if(con == 0) cout << "consonant" << endl;
    return 0;
}
