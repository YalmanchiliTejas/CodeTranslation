N,X,MOD = map(int,input().split())
L = [X%MOD]
S = set(L)
for i in range(1000000):
  X = pow(X,2,MOD)
  if X not in S:
    L.append(X)
    S.add(X)
  else:
    loop = X
    break
ans = 0
#print(L,loop)
k = len(L)
if k >= N: #ループよりもNが短い
  for i in range(N):
    ans += L[i]
  print(ans);exit()
for i in range(k):
  if L[i] != loop:
    ans += L[i]
    if i+1 == N:
      print(ans);exit()
  else: #ループに戻ってきた
    #print(i)
    loop_syuki = k-i
    saisyo = i
    loop_kosu = (N-saisyo)//loop_syuki
    amari = (N-saisyo)%loop_syuki
    nokori = loop_kosu*sum(L[saisyo:]) + sum(L[saisyo:saisyo+amari])
    ans += nokori
    #print(loop_syuki,saisyo,amari)
    print(ans);exit()