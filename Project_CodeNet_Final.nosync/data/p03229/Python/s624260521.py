n = int(input())
a = [0 for i in range(n)]
for i in range(n):
    a[i] = int(input())

a = sorted(a)
sum = 0

if n % 2 == 1:
    sum1 = 0
    for i in range(int(n/2)+1, n):
        sum1 += a[i] * 2
    sum1 -= a[int(n / 2)-1]
    sum1 -= a[int(n / 2)]
    for i in range(int(n / 2)-1):
        sum1 -= a[i]*2

    sum2 = 0
    for i in range(int(n/2), n):
        sum2 += a[i] * 2
    sum2 -= a[int(n / 2)]
    sum2 -= a[int(n / 2)+1]
    for i in range(int(n / 2)):
        sum2 -= a[i]*2
    print(max(sum1, sum2))
else:
    sum += a[int(n / 2)]
    for i in range(int(n / 2)+1, n):
        sum += a[i] * 2
    sum -= a[int(n / 2) - 1]
    for i in range(int(n / 2) - 1):
        sum -= a[i] * 2
    print(sum)
