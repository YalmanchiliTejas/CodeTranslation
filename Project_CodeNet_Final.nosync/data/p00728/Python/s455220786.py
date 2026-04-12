while True:
    n = int(input())
    if n == 0:
        break

    s = [int(input()) for i in range(n)]

    s.sort()
    ans = sum(s[1:n - 1]) // (n - 2)
    print(ans)
