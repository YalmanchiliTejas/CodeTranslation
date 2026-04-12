n=int(input())
l=list(map(int,input().split()))

sm=sum(l)
ans=0

for i in l:
  sm-=i
  ans+=i*sm
  ans%=1000000007
print(ans)