n = int(input())
a = list(map(int, input().split()))
ans = 0
b = 0
c = 0
for i in range(n):
    b += a[i]
    c += a[i] * a[i]
ans = (b * b - c) // 2
ans %= 1000000007
print(ans)
