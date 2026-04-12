import sys
input=sys.stdin.readline

N=int(input())
H=list(map(int,input().split()))
m=H[0];c=0
for i in range(0,N):
  if (H[i]>=H[0])and(H[i]>=m):
    c+=1
    m=max(H[0],H[i])
print(c)