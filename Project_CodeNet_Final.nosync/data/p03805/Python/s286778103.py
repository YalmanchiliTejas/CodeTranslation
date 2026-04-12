from itertools import permutations as per
ty,he=map(int,input().split())
l=[set(map(int,input().split())) for i in range(he)]
ans=0
for g in per(range(2,ty+1)):
  co=[1]+list(g)
  for sd in zip(co,co[1:]):
    if set(sd) not in l:break
  else:ans+=1
print(ans)