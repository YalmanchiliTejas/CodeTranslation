from collections import Counter
N=int(input())
d={chr(i):100 for i in range(ord("a"),ord("z")+1)}
for i in range(N):
  A={chr(i):0 for i in range(ord("a"),ord("z")+1)}
  A.update(Counter(list(input())))
  for i in A:
    if d[i]>A[i]:
      d[i]=A[i]
for i in d:
  if d[i]==100:
    d[i]=0
ans=""
key=sorted(d.keys())
for i in key:
  ans+=i*d[i]
print(ans)