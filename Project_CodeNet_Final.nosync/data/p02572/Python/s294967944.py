n=int(input())
hoge=list(map(int,input().split()))
ans=0
wa=hoge[0]
for i in range(1,n):
  ans+=wa*hoge[i]
  ans=ans%(10**9+7)
  wa+=hoge[i]
print(ans)