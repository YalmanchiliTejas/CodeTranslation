#include <bits/stdc++.h>
using namespace std;

int n;
int is_sheep[100000];   //-1: not sure, 0:wolve, 1: sheep
char answer[100000];
bool check_kind(int pos)
{
    int front_pos = (pos - 1 + n) % n;
    int back_pos = (pos + 1) % n;
    if(is_sheep[pos])
    {
        if(answer[pos] == 'o')
            return is_sheep[front_pos] == is_sheep[back_pos];
        else
            return is_sheep[front_pos] != is_sheep[back_pos];
    }
    else
    {
        if(answer[pos] == 'o')
            return is_sheep[front_pos] != is_sheep[back_pos];
        else
            return is_sheep[front_pos] == is_sheep[back_pos];
    }
}
bool is_valid()
{
    for(int i = 2; i < n; ++i)
    {
        if(answer[i - 1] == 'o')
        {
            if(is_sheep[i - 1])
                is_sheep[i] = is_sheep[i - 2];
            else
                is_sheep[i] = is_sheep[i - 2] ^ 1;
        }
        else
        {
            if(is_sheep[i - 1])
                is_sheep[i] = is_sheep[i - 2] ^ 1;
            else
                is_sheep[i] = is_sheep[i - 2];
        }
    }
    if(!check_kind(0) || !check_kind(n - 1))
        return false;
    return true;
}
void print_kind()
{
    for(int i = 0; i < n; ++i)
    {
        if(is_sheep[i])
            cout << 'S';
        else
            cout << 'W';
    }
    cout << endl;
}
int main()
{
    cin >> n;
    cin >> answer;
    for(int first_kind = 0;first_kind <= 1;++first_kind)
    {
        for(int second_kind = 0;second_kind <= 1;++second_kind)
        {
            is_sheep[0] = first_kind;
            is_sheep[1] = second_kind;
            if(is_valid())
            {
                print_kind();
                exit(0);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
