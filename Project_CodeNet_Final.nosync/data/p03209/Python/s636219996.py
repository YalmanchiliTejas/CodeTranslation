n,k = map(int,input().split())
pk = [1]
pz = [1]
for i in range(n):
  pk.append(pk[-1]*2+1)
  pz.append(pz[-1]*2+3)
ans = 0
for i in range(n,-1,-1):
  z = pz.pop()
  ka = pk.pop()
  if k>= z//2:
    ans += ka//2
    k-=z//2
    if k:
      ans+=1
  if k:
    k-=1
print(ans)