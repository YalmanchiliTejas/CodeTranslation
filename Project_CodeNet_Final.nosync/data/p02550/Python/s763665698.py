N,X,M = map(int, input().split())

a = X
s = set([a])
lst = [0]*M
lst[a] = 1
rlt = 0

j = 0
f = 1
for i in range(2,N+1):
  a = a**2 % M
  if a == 0:
    f = 2
    break
  elif a in s:
    j = lst[a]
    f = 0
    break
  else:
    lst[a] = i
    s.add(a)

if f > 0:
  print(sum(s))
else:
  t = 0
  k = i - j
  p = (N-j+1)//k
  r = (N-j+1)%k
  for u in range(1,M):
    if 0 < lst[u] < j:
      rlt += u
    elif lst[u] >= j:
      t += u
      if lst[u]-j+1 <= r:
        rlt += u
  rlt += t*p
  print(rlt)