n,m = map(int,input().split())
raw = [[] for _ in range(n)]
for _ in range(m):
  a,b = map(int,input().split())
  raw[a-1].append(b-1)
  raw[b-1].append(a-1)
#print(raw)
already = [0]
goal = [i for i in range(n)]
ans = 0
now = 0
last = 0
while True:
  try:
    if raw[now][last] not in already:
      now = raw[now][last]
      already.append(now)
      last = 0
    else:
      last += 1
  except:
    try:
      now = already[-2]
      last = raw[now].index(already[-1])+1
      already = already[:-1]
    except:
      print(ans)
      break
  if sorted(already) == goal:
    ans += 1
    now = already[-2]
    last = raw[now].index(already[-1])+1
    already = already[:-1]
  #print(now,already,last)