n=int(input())
l=list(map(int,input().split()))

rs=[0]*n
rs[0]=l[-1]
j=1
for i in range(n-2,-1,-1):
    rs[j]=rs[j-1]+l[i]
    j+=1
rs=rs[::-1]

ans=0
for i in range(n-1):
    ans+=(l[i]*rs[i+1])
print(ans%(10**9+7))
