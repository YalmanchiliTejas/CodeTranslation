H,W = map(int,input().split())
S = []
for _ in range(H):
  a = list(input())
  if a.count('.') < W: S.append(a)
S_t = list(map(list, zip(*S)))
S_re = []
for i in range(W):
  if S_t[i].count('.') < len(S): S_re.append(S_t[i])

S_tt = list(map(list, zip(*S_re)))
for i in S_tt:
  print(''.join(i))
