n=int(input())
a=[int(input()) for i in range(n)]
a.sort()
t=n//2
if(n%2==0):
    ans=a[t]-a[t-1]+(sum(a[t+1:])-sum(a[:t-1]))*2
else:
    a1=(sum(a[t+1:])-sum(a[:t-1]))*2-a[t]-a[t-1]
    a2=(sum(a[t+2:])-sum(a[:t]))*2+a[t]+a[t+1]
    ans=max(a1,a2)
print(ans)