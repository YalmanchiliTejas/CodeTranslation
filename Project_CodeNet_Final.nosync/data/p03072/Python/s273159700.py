s=0
N=int(input())
L=list(map(int,input().split()))
for i in range(N):
  if max(L[:i+1])==L[i]:
    s+=1
print(s)