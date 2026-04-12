#include <iostream>
#include <string>
using namespace std;

int main() {
    char *s;
    char buf[512];
    int n;

    cin >> buf;
    s = (char*) malloc(strlen(buf) + 1);
    char *t = s;
    for(int i=0; buf[i]!='\0'; i++){
        s[i]=buf[i];
    }

    for (int i = 0; i < strlen(s); ++i) {
        if(*s == 'A'){
            s++;
            if (*s == 'C') {
                cout << "Yes" << endl;
                free(t);
                return 0;
            }
            s--;
        }
        s++;
    }
    cout << "No" << endl;

    free(t);

    return 0;
}