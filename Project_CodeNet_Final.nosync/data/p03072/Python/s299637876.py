n=int(input())
hoge=list(map(int,input().split()))
ans=0
max=0
for i in range(n):
  if(max<=hoge[i]):
    ans+=1
    max=hoge[i]

print(ans)