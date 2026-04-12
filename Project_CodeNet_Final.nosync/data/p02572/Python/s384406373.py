n=int(input())
a=list(map(int,input().split()))
s=sum(a)#aの総和
ans=0
for i in range(n-1):
    s-=a[i]
    tmp=a[i]*s
    ans+=tmp
print(ans%(10**9 +7))