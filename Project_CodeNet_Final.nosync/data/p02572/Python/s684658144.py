n = int(input())
a = [int(i) for i in input().split()]
#n = (10**5)*2
#n = 10
#a = [int(10**9)]*n
mod = (10**9)+7
ans = 0
c = [0]*n
c[n-1] = a[n-1]
for i in range(n-1,1,-1) :
    c[i-1] = c[i]+a[i-1]
c.pop(0)
for i in range(0,n-1) :
    ans += (a[i]*c[i])

print(ans%mod)