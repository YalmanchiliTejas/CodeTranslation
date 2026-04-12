n = int(input())
a = list(map(int, input().split()))

s = 0
ss = 0
for i in range(n):
    j = n - i - 1
    s += (a[j] * ss % (10**9 + 7))
    s %= (10**9 + 7)
    ss += a[j]

print(s)
