#include <iostream>
using namespace std;

int main()
{
    char a;
    cin >> a;
    if(a== 'a'||a=='e'||a=='u'||a=='o'||a=='i'){
        cout << "vowel";
        return 0;
    }
    cout << "consonant";
    return 0;
}
