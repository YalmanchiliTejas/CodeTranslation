import itertools
n,m = map(int,input().split())
ab = []
count = 0
for i in range(m):
  ab.append(set(map(int,input().split())))
ns = [i for i in range(1,n+1)]
ptn = [i for i in list(itertools.permutations(ns)) if i[0]==1]
for i in ptn:
  first = i[0]
  for s in range(1,n):
    if {first,i[s]} not in ab:
      break
    first=i[s]
  else:
    count +=1
print(count)