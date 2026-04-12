n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
tmp = 0
sum = 0
for i in range(n):
    sum += a[i]
    sum %= mod
for i in range(n-1):
    sum -= a[i]
    if sum<0:
        sum+=mod
    tmp += a[i]*sum
    tmp %= mod 
print(tmp)