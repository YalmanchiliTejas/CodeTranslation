mod = 10**9+7
n = int(input())
a = [int(i) for i in input().split()]

sum_a = [0]*(n-1)
sum_a[0] = a[n-1]

for i in range(1,n-1):
    sum_a[i] = sum_a[i-1] + a[n-1-i]
    
ans = 0

for i in range(n-1):
    #print(n-1-i)
    ans += a[i]*sum_a[n-2-i]
    ans %= mod
    
print(ans)