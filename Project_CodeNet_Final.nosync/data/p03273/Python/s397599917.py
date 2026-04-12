H, W = map(int, input().split())
G = []

for i in range(H):
  line = input()
  if line != '.' * W:
    G.append(line)

H = len(G)
ans = []

for i in range(W):
  flg = False
  tmp = ''
  for j in range(H):
    if G[j][i] == '.':
      flg = False
    else:
      flg = True
    tmp += G[j][i]
  if tmp != '.' * H:
    ans.append(tmp)

for i in range(H):
  tmp = ''
  for j in range(len(ans)):
    tmp += ans[j][i]
  print(tmp)