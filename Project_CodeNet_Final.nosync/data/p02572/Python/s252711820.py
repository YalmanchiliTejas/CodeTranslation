n=int(input())
a=list(map(int,input().split()))

mo=10**9+7
an=0
wk=0
ru=[]
for i in a:
    wk+= i
    ru.append(wk%mo)
for i in range(n-1):
    an+=a[i]*(ru[n-1]-ru[i])
    an%=mo

print(an)