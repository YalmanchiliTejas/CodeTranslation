n=int(input())
a=list(map(int,input().split()))
mod = 10**9 + 7

sum = 0
f = 0

for i in range(n-1):
    f = f + a[i]
    sum += f * a[i+1]
 
print(sum % mod)