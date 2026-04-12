H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

b = [list(x) for x in zip(*a)]

n = []
for i in range(W):
  if b[i] == ["."] * H: 
    n.append(i)

for A in a:
  if A == ["."] * W: continue
  if len(n) == 0: 
    print("".join(A))
    continue
  ans = ""
  for i in range(W):
    if i in n: continue
    ans += A[i]
  print("".join(ans))