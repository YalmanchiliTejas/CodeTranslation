import sys
readline = sys.stdin.readline

for _ in range(int(readline())):
    a = int(readline())
    y = int(readline())
    n = int(readline())
    ans = a
    for _ in range(n):
        t, rate, fee = [f(x) for f, x in zip((int, float, int), readline().split())]
        if t == 1:
            res = a
            for _ in range(y):
                res = res + int(res * rate) - fee
        else:
            res = a
            r = 0
            for _ in range(y):
                r += int(res * rate)
                res = res - fee
            res += r
        ans = max(ans, res)
    print(ans)