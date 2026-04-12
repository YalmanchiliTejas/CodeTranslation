N, X, M = map(int, input().split())

tmp = [0 for i in range(M+2)]
r = [0 for i in range(M)]
tmp[1] = X
r[X] = 1 # A_1 = X
flag = False
for i in range(2, N+1):
  X = (X * X) % M
  #tmp[i] = tmp[i-1] + X
  tmp[i] = X
  if r[X] == 0:
    r[X] = i
  else:
    flag = True
    p = i - r[X]
    #pt = tmp[i] - tmp[r[X]]
    pt = 0
    for j in range(r[X]+1, i+1):
      pt += tmp[j]
    tmp_rX = 0
    for j in range(1, r[X]+1):
      tmp_rX += tmp[j]
    # ans = tmp[r[X]] + pt * ((N - r[X]) // p) + (N - r[X]) % p
    p_r = (N - r[X]) % p
    #T_r = tmp[r[X] + p_r] - tmp[r[X]]
    T_r = 0
    for j in range(1,p_r+1):
      T_r += tmp[ r[X] + j ]
    #ans = tmp[r[X]] + pt * ((N - r[X]) // p) + T_r
    ans = tmp_rX + pt * ((N - r[X]) // p) + T_r
    break
    
if flag:
  print(ans)
else:
  print(sum(tmp))