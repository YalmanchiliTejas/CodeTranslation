n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
ans = -2 * sum(a[:n // 2])
if n % 2 == 0:
    ans += 2 * sum(a[n // 2:]) + a[n // 2 - 1] - a[n // 2]
else:
    ans += 2 * sum(a[n // 2 + 1:]) + max(a[n // 2 - 1] - a[n // 2], a[n // 2] - a[n // 2 + 1])
print(ans)