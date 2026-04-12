while True:
    n = int(input())
    if n == 0:
        break

    s = [int(input()) for i in range(n)]
    s.sort()
    score = sum(s) - s[0] - s[-1]
    print(score // (n - 2))
