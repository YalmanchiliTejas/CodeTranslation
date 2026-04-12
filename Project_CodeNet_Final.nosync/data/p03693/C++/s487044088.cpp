#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g, r;
    cin.ignore();
    cin >> g >>r;
    cout << (((10*g+r)%4==0)?"YES\n":"NO\n");
    return 0;
}