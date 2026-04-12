n = int(input())
a = list(map(int,input().split()))
 
mod = 10**9+7
sum_a = sum(a)%mod
sum_a2 = sum_a**2%mod
 
for i in range(n):
    sum_a2 -= (a[i]**2)%mod
    sum_a2 %= mod
    
if sum_a2%2 == 0:
    ans = sum_a2//2
else:
    ans = ((sum_a2+mod)//2)%mod

print(ans)