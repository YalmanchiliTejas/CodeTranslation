h,w=map(int,input().split())
s = []
wl = [0]*w
hl = [0]*h
for _ in range(h):
  s.append(input())
for i in range(h):
  if s[i].count("#") == 0:
    hl[i] = 1
for j in range(w):
  cnt = 0
  for i in range(h):
    if s[i][j] == "#":
      break
    cnt += 1
  if cnt == h:
    wl[j] = 1
ans=[]
for i in range(h):
  tmp =""
  if hl[i] == 0:
    for j in range(w):
      if wl[j] == 0:
        tmp += s[i][j]
    ans.append(tmp)
for x in ans:
  print(x)