#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{

    int n,k;
    char s[1024];

    char searchchar;
    int cnter = 0;
    cin >> n >> s >> k;
    
    searchchar = s[k-1];

    while(s[cnter]){
        if(s[cnter] != searchchar){
            s[cnter] = '*';
        }
        cnter++;
    }

    
    cout << s << endl;
    return 0;

}

//Yesterday,allmytroublesseemedsofaraway