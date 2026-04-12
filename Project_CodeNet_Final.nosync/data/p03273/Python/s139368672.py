H, W = map(int, input().split())

A = []
for i in range(H):
  S = input()
  if S.count(".") != W:
    A.append(S)

c = zip(*[i for i in zip(*A) if "#" in i])
for d in c:
  print("".join(d))