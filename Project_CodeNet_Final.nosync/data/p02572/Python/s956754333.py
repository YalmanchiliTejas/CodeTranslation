N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7
ans = 0
sum = 0
m = 0
for a in A:
    sum = sum + a
    m += a**2
ans = sum**2-m
print((ans//2)%mod)