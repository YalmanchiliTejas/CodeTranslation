while True:
    n, l, r = map(int, input().split())
    if n+l+r == 0:
        break
    As = [int(input()) for _ in range(n)]
    ans = 0
    for jj in range(l, r+1):
        flag = False
        for i, a in enumerate(As):
            if flag:
                break
            if jj % a == 0:
                if (i+1) % 2 == 1:
                    flag = True
                    ans += 1
                    break
                else:
                    flag = True
        if flag:
            continue
        else:
            if n % 2 == 0:
                ans += 1

    print(ans)
