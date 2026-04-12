n = int(input())
a = [int(input()) for _ in range(n)]
a = sorted(a)
la = len(a)

if n % 2 == 0:
    p = la // 2
    ans = (sum(a[p:]) - sum(a[:p])) * 2 + a[p - 1] - a[p]
else:
    p = la // 2
    ans = (sum(a[p:]) - sum(a[:p])) * 2 - a[p] - a[p + 1]

    p = la // 2 + 1
    t = (sum(a[p:]) - sum(a[:p])) * 2 + a[p - 2] + a[p - 1]

    ans = max(ans, t)

print(ans)