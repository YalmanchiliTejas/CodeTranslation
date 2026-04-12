#include <iostream>
#include <cstdio>
 
using namespace std;
 
typedef unsigned long long ull;
 
int t[100000];
 
bool judge(int N, string s)
{
    for (int i = 2; i < N; i++)
    {
        auto isBothAnimal = s[i - 1] == 'o' ? true : false;
        
        // 羊, 羊, X
        if (t[i - 2] == 0 && t[i - 1] == 0)
        {
            t[i] = isBothAnimal ? 0 : 1;
        }
        // 羊, 狼, X
        else if (t[i - 2] == 0 && t[i - 1] == 1)
        {
            t[i] = isBothAnimal ? 1 : 0;
        }
        // 狼, 羊, X
        else if (t[i - 2] == 1 && t[i - 1] == 0)
        {
            t[i] = isBothAnimal ? 1 : 0;
        }
        // 狼, 狼, X
        else if (t[i - 2] == 1 && t[i - 1] == 1)
        {
            t[i] = isBothAnimal ? 0 : 1;
        }
    }
    
    bool isFirstOk = false;
    if (t[0] == 0)
    {
        if (s[0] == 'o' && t[N - 1] == t[1])
        {
            isFirstOk = true;
        }
        else if (s[0] == 'x' && t[N - 1] != t[1])
        {
            isFirstOk = true;
        }
    }
    else
    {
        if (s[0] == 'o' && t[N - 1] != t[1])
        {
            isFirstOk = true;
        }
        else if (s[0] == 'x' && t[N - 1] == t[1])
        {
            isFirstOk = true;
        }
    }
    
    bool isEndOk = false;
    if (t[N - 1] == 0)
    {
        if (s[N - 1] == 'o' && t[N - 2] == t[0])
        {
            isEndOk = true;
        }
        else if (s[N - 1] == 'x' && t[N - 2] != t[0])
        {
            isEndOk = true;
        }
    }
    else
    {
        if (s[N - 1] == 'o' && t[N - 2] != t[0])
        {
            isEndOk = true;
        }
        else if (s[N - 1] == 'x' && t[N - 2] == t[0])
        {
            isEndOk = true;
        }
    }
    
    return isFirstOk && isEndOk;
}
 
void print(int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%s", t[i] == 0 ? "S" : "W");
    }
    printf("\n");
}
 
int main()
{
    int N;
    string s;
    
    cin >> N;
    cin >> s;
    
    // 羊、羊
    t[0] = 0;
    t[1] = 0;
    if (judge(N, s))
    {
        print(N);
        return 0;
    }
    
    // 羊、狼
    t[0] = 0;
    t[1] = 1;
    if (judge(N, s))
    {
        print(N);
        return 0;
    }
 
    // 狼、羊
    t[0] = 1;
    t[1] = 0;
    if (judge(N, s))
    {
        print(N);
        return 0;
    }
 
    // 狼、狼
    t[0] = 1;
    t[1] = 1;
    if (judge(N, s))
    {
        print(N);
        return 0;
    }
    
    printf("-1\n");
    
    return 0;
}
