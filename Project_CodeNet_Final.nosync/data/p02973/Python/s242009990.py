import bisect

N=int(input())
A=[-int(input()) for i in range(N)]

B=[]
c=0
for a in A:
  p=bisect.bisect_right(B,a)
  if p==c:
    B.append(a)
    c += 1
  else:
    B[p]=a

print(len(B))
