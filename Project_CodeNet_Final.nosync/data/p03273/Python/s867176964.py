H, W = map(int, input().split())
S = [list(input()) for h in range(H)]

while True:
  ans = 0
  for h in range(H):
    if list(set(S[h]))[0] == ".":
      S.pop(h)
      H -= 1
      ans = 1
      #print(S)
      #print()
      break
  for w in range(W):
    #print([S[h][w] for h in range(H)])
    if list(set([S[h][w] for h in range(H)]))[0] == ".":
      for h in range(H):
        S[h].pop(w)
      W -= 1
      ans = 1
      #print(S)
      #print()
      break
  if ans == 0:
    break

for h in range(H):
  print("".join(S[h]))