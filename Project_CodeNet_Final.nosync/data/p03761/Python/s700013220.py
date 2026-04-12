n = int(input())
Cands = list(input())
for i in range(n-1):
  temp = []
  S = list(input())
  for cand in Cands:
    if cand in S:
      temp.append(cand)
      S.pop(S.index(cand))
  Cands = temp
Cands = sorted(Cands)
print(*Cands, sep="")