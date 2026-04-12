mod = 10**9+7
n = int(input())
a = list(map(int, input().split()))
s = [0]*(n-1)
for i in range(n-1):
    if i == 0:
        s[i] = a[-i-1]
    else:
        s[i] = s[i-1] + a[-i-1]
        s[i] %= mod
ans = 0
for i in range(n-1):
    ans += s[i]*a[-i-2]
    ans %= mod
print(ans)