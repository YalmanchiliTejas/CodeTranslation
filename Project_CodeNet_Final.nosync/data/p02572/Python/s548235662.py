mod=1000000007
n=int(input())
#n,k=map(int,input().split())
a=[int(i) for i in input().split()]
t=[0]*(n+1)
for i in range(n):
    t[i]=t[i-1]+a[i]
ans=chk=0
#print(t)
for i in range(n-1):
#    print(-(i+1))
    x=-1*(i+1)
#    print(x)
#    print(a[x],t[x-2])
    ans+=a[x]*t[x-2]
    ans%=mod
print(ans)