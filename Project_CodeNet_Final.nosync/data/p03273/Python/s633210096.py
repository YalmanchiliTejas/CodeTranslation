H, W = map(int, input().split())
L = []
brank = "." * W
ban = []
for _ in range(H):
  s = input()
  if brank == s:
    continue
  L.append(list(map(str, s)))
  
for i in range(W):
  for l in L:
    if l[i] != ".":
      break
  else:
    ban.append(i)
    continue

for l in L:
  ans = ""
  for i in range(W):
    if i in ban:
      continue
    ans += l[i]
  print(ans)