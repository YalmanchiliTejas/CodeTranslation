s = int(input())
a = list(map(int,input().split()))
mod = 10 ** 9 + 7
ans = 0
sum_a = sum(a)
for i in range(s):
    sum_a -= a[i]
    ans += sum_a * a[i] % mod
print(ans%mod)