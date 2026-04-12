n = int(input())
a = list(map(int, input().split()))
ans = 0
r = [0] * (n + 1)
for i, v in enumerate(a, start=1):
    r[i] = v + r[i - 1]

for i in range(n - 1):
    ans += a[i + 1] * r[i + 1]

print(ans % (10 ** 9 + 7))
