n = int(input())
a = list(map(int, input().split()))
s1 = sum(a)
s2 = 0
ans = 0
for i in range(n - 1):
    s2 += a[i]
    ans += a[i] * (s1 - s2)
print(ans % 1000000007)
