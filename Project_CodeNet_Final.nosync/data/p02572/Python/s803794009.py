n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
aa = [a[0] % mod]
for i in range(1, n-1):
    aa.append((aa[i-1] + a[i]) % mod)
ans = 0
for i in range(n-1):
    ans += ((aa[i] * a[i+1]) % mod)
print(ans % mod)