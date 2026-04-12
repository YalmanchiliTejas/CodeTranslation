while True:
    n, l, r = map(int, input().split())
    if n == 0:
        break
    A = [int(input()) for _ in range(n)]

    ans = 0
    for x in range(l, r + 1):
        checked = False
        for i, a in enumerate(A):
            if x % a == 0:
                ans += (i % 2 == 0)
                checked = True
                break
        if not checked and n % 2 == 0:
            ans += 1
    print(ans)
