n=int(input())
l=list(map(int,input().split()))
infin=10**9+7
s=0
for i in range(0,len(l)):
  s+=l[i]
ans=0
for i in range(len(l)-1,0,-1):
  s=s-l[i]
  ans=(ans+l[i]*s)%infin
print(ans)
  