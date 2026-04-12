while True:

    n, a, b, c, x = map(int, input().split(" "))

    if n == 0 and a == 0 and b == 0 and c == 0 and x == 0:
        break

    y = list(map(int, input().split(" ")))

    ans = 0
    i = 0
    
    while ans <= 10000:
        if x == y[i]:
            i += 1

        if i == n:
            break
        x = (a * x + b) % c
        ans += 1
    if ans >= 10001:
        ans = -1
    print(ans)

