n = int(input())
a = list(map(int, input().split()))
a_sum = 0
s = []
ans = 0

for i in range(n):
    a_sum += a[i]
    s.append(a_sum)

for i, j in enumerate(a):
    ans += j * (s[n - 1] - s[i])

print(ans % (10 ** 9 + 7))
