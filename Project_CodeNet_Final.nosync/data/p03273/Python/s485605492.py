H, W = map(int, input().split())
L = []
brank = "." * W
for _ in range(H):
  S = input()
  if S == brank:
    continue
  L.append(list(map(str, S)))

if L:
  L1 = list(zip(*L))
  brank = tuple(["." for _ in range(len(L1[0]))])
  ans = []

  for l in L1:
    if l == brank:
      continue
    ans.append(l)


  for a in zip(*ans):
    print("".join(a))