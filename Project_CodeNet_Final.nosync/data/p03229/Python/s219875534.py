n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
if n % 2 == 0:
    lower = a[:n//2]
    upper = a[n//2:]
    x = 2 * sum(upper) - upper[0]
    y = 2 * sum(lower) - lower[-1]
    ans = x - y
else:
    lower = a[:n//2]
    upper = a[n//2+1:]
    mid = a[n//2]
    x = 2 * sum(upper) - 2 * sum(lower) - mid + lower[-1]
    y = 2 * sum(upper) - 2 * sum(lower) + mid - upper[0]
    ans = max(x, y)
print(ans)
