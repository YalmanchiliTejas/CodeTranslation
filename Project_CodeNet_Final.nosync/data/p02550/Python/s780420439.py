N,X,M = map(int, input().split())

LOOP = [X]
wk = X
s = set()
s.add(X)
flg = True
for i in range(N-1):
  a = wk * wk % M
  if a == 0:
    print(sum(LOOP))
    exit(0)
  if a in s:
    wk = a
    flg = False
    break
  LOOP.append(a)
  s.add(a)
  wk = a
#print(LOOP)
if flg:
  print(sum(LOOP))
else:
  for i in range(len(LOOP)):
    if LOOP[i] == wk:
      beg_i = i
      break
  fin_i = len(LOOP) -1
  ans = sum(LOOP[:beg_i])
  N -= beg_i
  L = LOOP[beg_i:]
  LS = len(L)
  #print(LS)
  ans += sum(L) * (N//LS)
  N = N % LS
  ans += sum(L[:N])
  print(ans)
