n = int(input())
a = list(map(int,input().split()))
s = sum(a)
ans = 0

for i in range(n-1):
    s -= a[i]
    ans += a[i]*s
m = 7 + 10**9
print(ans%m)
