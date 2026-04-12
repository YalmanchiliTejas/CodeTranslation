n=int(input())
m=list(map(int,input().split()))
maximum=0
ans=0
for i in range(n):
  if m[i]>=maximum:
    maximum=m[i]
    ans+=1
print(ans)