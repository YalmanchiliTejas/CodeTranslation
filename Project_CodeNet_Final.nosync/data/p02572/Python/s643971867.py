N=int(input())
l=list(map(int,input().split()))
ans=0
i=0
S=sum(l)
while i<len(l)-1:
  S=S-l[i]
  ans+=l[i]*S
  i+=1
print(ans%1000000007)