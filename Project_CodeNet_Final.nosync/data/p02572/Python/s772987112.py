n = int(input())
a = list(map(int, input().split()))
su = sum(a)
ans = 0

for i in range(n-1):
    su -= a[i]
    ans += (a[i]*su)

print(ans%(10**9+7))