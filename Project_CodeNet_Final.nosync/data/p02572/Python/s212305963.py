n= int(input())
a= [int(i) for i in input().split()]
pref=[0]*n
m = 10**9+7
pref[0] = a[0]%m
for i in range(1,n):
    pref[i] =  (pref[i-1]+a[i])%m
m = 10**9+7
ans = 0
#print(pref)
for i in range(n-1):
    ans+= (a[i]%m *((pref[n-1]-pref[i])%m))%m
    ans = ans%m
print(ans)