n = int(input())
a = list(map(int,input().split()))
su = 0
mod = 10**9+7
sum_a = 0
for i in range(n):
    sum_a += a[i]
    sum_a %= mod

for i in range(n-1):
    sum_a -= a[i]
    su += a[i]*sum_a
    su %= mod
print(su)