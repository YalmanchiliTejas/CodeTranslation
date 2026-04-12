N,x,MOD = map(int, input().split())
s = x
flag = False
sflag = False
if N == 1:
  flag = True
  sflag = True
  print(s)
for i in range(1,MOD):
  x = (x*x) % MOD
  s += x
  if N == (i+1):
    flag = True
    break
if flag == True:
  if sflag == False:
    print(s)
else:
  t_s = 0
  cnt = 0
  init = x
  for i in range(MOD):
    x = (x*x) % MOD
    t_s += x
    cnt += 1
    if x == init:
      break
  bi = (N-MOD)//cnt
  res = (N-MOD)%cnt
  s += t_s * bi
  for i in range(res):
    x = (x*x) % MOD
    s += x
  print(s)