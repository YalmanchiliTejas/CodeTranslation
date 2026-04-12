N, X, M = map(int, input().split())
tmp = X
seq = []
ans = 0
for i in range(N):
  if X in seq:
    break
  seq.append(X)
  X = (X ** 2) % M

ans = sum(seq[:min(N, len(seq))])
N -= len(seq)
if N < 1:
    print(ans)
    exit()
i = seq.index(X)
l = len(seq) - i
ans += sum(seq[i:]) * (N//l)
N %= l
ans += sum(seq[i:i+N])
print(ans)
