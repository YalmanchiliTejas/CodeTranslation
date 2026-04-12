n = int(input())
a = list(map(int,input().split()))

a2=[a[n-1]]
for i in range(n-1,0,-1):
    a2.append(a2[-1]+a[i-1])
ans=0
for i in range(n-1):
    ans = ( ans + (a[i]*a2[-i-2]) )%(10**9+7)
print(ans)
