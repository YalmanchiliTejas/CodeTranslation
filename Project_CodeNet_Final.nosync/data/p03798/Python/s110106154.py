n = int(input())
s = input()

def test(ans):
    f = True
    for i in range(1, n - 1):
        if ans[i] == 'S':
            if ans[i - 1] == 'S' and s[i] == 'o':
                ans += 'S'
            elif ans[i - 1] == 'S' and s[i] == 'x':
                ans += 'W'
            elif ans[i - 1] == 'W' and s[i] == 'o':
                ans += 'W'
            elif ans[i - 1] == 'W' and s[i] == 'x':
                ans += 'S'
        else:
            if ans[i - 1] == 'S' and s[i] == 'o':
                ans += 'W'
            elif ans[i - 1] == 'S' and s[i] == 'x':
                ans += 'S'
            elif ans[i - 1] == 'W' and s[i] == 'o':
                ans += 'S'
            elif ans[i - 1] == 'W' and s[i] == 'x':
                ans += 'W'

    # i = n-1
    if ans[n-1] == 'S' and s[n-1] == 'o':
        if ans[n-2] != ans[0]:
            f = False
    elif ans[n-1] == 'S' and s[n-1] == 'x':
        if ans[n-2] == ans[0]:
            f = False
    elif ans[n-1] == 'W' and s[n-1] == 'o':
        if ans[n-2] == ans[0]:
            f = False
    elif ans[n-1] == 'W' and s[n-1] == 'x':
        if ans[n-2] != ans[0]:
            f = False

    # i == 0
    if ans[0] == 'S' and s[0] == 'o':
        if ans[n-1] != ans[1]:
            f = False
    elif ans[0] == 'S' and s[0] == 'x':
        if ans[n-1] == ans[1]:
            f = False
    elif ans[0] == 'W' and s[0] == 'o':
        if ans[n-1] == ans[1]:
            f = False
    elif ans[0] == 'W' and s[0] == 'x':
        if ans[n-1] != ans[1]:
            f = False

    return ans, f


# SS
ans1, f1 = test('SS')
ans2, f2 = test('SW')
ans3, f3 = test('WW')
ans4, f4 = test('WS')

if f1:
    print(ans1)
elif f2:
    print(ans2)
elif f3:
    print(ans3)
elif f4:
    print(ans4)
else:
    print(-1)
