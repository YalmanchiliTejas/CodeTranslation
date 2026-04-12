mod = 1000000007
n = int(input())
a = list(map(int,input().split()))
ans = 0
b = sum(a)
for i in range(n-1):
    b = b-a[i]
    ans += (a[i]*(b))%mod
print(ans%mod)