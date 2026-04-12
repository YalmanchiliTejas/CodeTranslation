def abc115_d():
    n, x = map(int, input().split())
    l = [1] * 51
    p = [1] * 51
    for i in range(50):
        l[i + 1] = 2 * l[i] + 3
        p[i + 1] = p[i] * 2 + 1

    ans = 0
    while n:
        if x == l[n]:
            ans += p[n]
            break
        elif x > (l[n] // 2):
            ans += p[n - 1] + 1
            x -= (l[n - 1] + 2)
            n -= 1
        else:
            x -= 1
            n -= 1
    if x == 1:
        ans += 1

    print(ans)


abc115_d()