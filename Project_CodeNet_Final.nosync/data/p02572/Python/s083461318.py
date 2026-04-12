n = int(input())
a = list(map(int, input().split()))
 
sum = 0
sum1 = 0
mod = 1000000000+7
for i in range(n):
    if a[i] >= mod:
        a[i] = a[i] % mod
    sum1 += a[i]
    sum1 %= mod
    
for i in range(n-1):
    #for j in range(i+1, n):
    sum1 -= a[i]
    #sum += a[i] * a[j]
    if sum1 < 0:
        sum1 += mod
    sum += a[i] * sum1
    sum %= mod
            
print(sum)