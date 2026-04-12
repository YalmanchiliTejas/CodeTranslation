N=int(input())
H=[0]+list(map(int,input().split(' ')))
ans=0
for i in range(N):
  if H[i+1]>=max(H[:i+1]):
    ans+=1
print(ans)
