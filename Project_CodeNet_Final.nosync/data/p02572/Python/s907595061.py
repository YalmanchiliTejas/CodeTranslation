n=int(input())
a = list(map(int,input().split()))
mod = 10**9 +7
s = 0
ss =0
for i in range(n):
    s += a[i]
    ss += a[i] * a[i]

ans = (s*s - ss)//2
print(ans%mod)
