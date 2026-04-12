n = int(input())
a = list(map(int, input().split()))
s = [0] * n

for i in range(1, n):
    s[i] = s[i-1] + a[i-1]

ans = 0
for i in range(1, n):
    ans += a[i] * s[i]

mod = 10**9 + 7

# for i in range(n-1):
#     for j in range(i+1, n):
#         ans += a[i]*a[j]

print(ans%mod)

