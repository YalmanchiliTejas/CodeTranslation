#include <cstdio>
#define MAXN 100000 + 100
char str[MAXN], ans[MAXN];
int n;

void fill(int i) {
    if(ans[i] == 'S') {
        if(ans[i-1] == 'S') {
            if(str[i] == 'o')
                ans[i+1] = 'S';
            else if(str[i] == 'x')
                ans[i+1] = 'W';
        }else if(ans[i-1] == 'W') {
            if(str[i] == 'o')
                ans[i+1] = 'W';
            else if(str[i] == 'x')
                ans[i+1] = 'S';
        }
    }else if(ans[i] == 'W')  {
        if(ans[i-1] == 'S') {
            if(str[i] == 'o')
                ans[i+1] = 'W';
            else if(str[i] == 'x')
                ans[i+1] = 'S';
        }else if(ans[i-1] == 'W') {
            if(str[i] == 'o')
                ans[i+1] = 'S';
            else if(str[i] == 'x')
                ans[i+1] = 'W';
        }
    }
}

bool check() {
    if(ans[n] == 'S') {
        if(ans[n-1] == 'S') {
            if(str[n] == 'o')
                if(ans[1] == 'S')
                    return true;
                else return false;
            else if(str[n] == 'x')
                if(ans[1] == 'W')
                    return true;
                else return false;
        }else if(ans[n-1] == 'W') {
            if(str[n] == 'o')
                if(ans[1] == 'W')
                    return true;
                else return false;
            else if(str[n] == 'x')
                if(ans[1] == 'S')
                    return true;
                else return false;
        }
    }else if(ans[n] == 'W') {
        if(ans[n-1] == 'S') {
            if(str[n] == 'o')
                if(ans[1] == 'W')
                    return true;
                else return false;
            else if(str[n] == 'x')
                if(ans[1] == 'S')
                    return true;
                else return false;
        }else if(ans[n-1] == 'W') {
            if(str[n] == 'o')
                if(ans[1] == 'S')
                    return true;
                else return false;
            else if(str[n] == 'x')
                if(ans[1] == 'W')
                    return true;
                else return false;
        }
    }
}

bool check2() {
    if(ans[1] == 'S') {
        if(ans[n] == 'S') {
            if(str[1] == 'o')
                if(ans[2] == 'S')
                    return true;
                else return false;
            else if(str[1] == 'x')
                if(ans[2] == 'W')
                    return true;
                else return false;
        }else if(ans[n] == 'W') {
            if(str[1] == 'o')
                if(ans[2] == 'W')
                    return true;
                else return false;
            else if(str[1] == 'x')
                if(ans[2] == 'S')
                    return true;
                else return false;
        }
    }else if(ans[1] == 'W') {
        if(ans[n] == 'S') {
            if(str[1] == 'o')
                if(ans[2] == 'W')
                    return true;
                else return false;
            else if(str[1] == 'x')
                if(ans[2] == 'S')
                    return true;
                else return false;
        }else if(ans[n] == 'W') {
            if(str[1] == 'o')
                if(ans[2] == 'S')
                    return true;
                else return false;
            else if(str[1] == 'x')
                if(ans[2] == 'W')
                    return true;
                else return false;
        }
    }
}

int main() {
    scanf("%d\n%s", &n, str+1);
    ans[1] = ans[2] = 'S';
    for(int i = 2; i < n; i++)
        fill(i);
    if(check() && check2()) {
        for(int i = 1; i <= n; i++)
            printf("%c", ans[i]);
        return 0;
    }

    ans[1] = ans[2] = 'W';
    for(int i = 2; i < n; i++)
        fill(i);
    if(check() && check2()) {
        for(int i = 1; i <= n; i++)
            printf("%c", ans[i]);
        return 0;
    }

    ans[1] = 'W';
    ans[2] = 'S';
    for(int i = 2; i < n; i++)
        fill(i);
    if(check() && check2()) {
        for(int i = 1; i <= n; i++)
            printf("%c", ans[i]);
        return 0;
    }

    ans[1] = 'S';
    ans[2] = 'W';
    for(int i = 2; i < n; i++)
        fill(i);
    if(check() && check2()) {
        for(int i = 1; i <= n; i++)
            printf("%c", ans[i]);
        return 0;
    }
    printf("-1\n");
    return 0;
}
