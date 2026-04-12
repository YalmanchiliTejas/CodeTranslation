n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort()

ans = -1

if n % 2 == 1:
    sum2 = 0
    sum1 = 0
    for i in range(n):
        if n // 2 - 1 <= i <= n // 2:
            sum1 -= a[i]
        elif i < n // 2:
            sum2 -= a[i]
        else:
            sum2 += a[i]
    ans = max(ans, sum2 * 2 + sum1)

    a.reverse()
    sum2 = 0
    sum1 = 0
    for i in range(n):
        if n // 2 - 1 <= i <= n // 2:
            sum1 += a[i]
        elif i < n // 2:
            sum2 += a[i]
        else:
            sum2 -= a[i]
    ans = max(ans, sum2 * 2 + sum1)
else:
    Sum = 0
    for i in range(n):
        if i == n // 2 - 1:
            Sum -= a[i]
        elif i == n // 2:
            Sum += a[i]
        elif i < n // 2:
            Sum -= a[i] * 2
        else:
            Sum += a[i] * 2
    ans = max(ans, Sum)
    
    
print(ans)