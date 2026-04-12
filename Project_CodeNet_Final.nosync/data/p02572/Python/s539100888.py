n = int(input())
a = list(map(int, input().split()))
mod = 1000000007
t = [0]
t.append(a[-1])
for i in range(n - 2, -1, -1) :
    t.append((t[-1] + a[i]) % mod)
ans = 0
for i in range(n) :
    ans = (ans + a[i] * t[n - i - 1]) % mod
print(ans)