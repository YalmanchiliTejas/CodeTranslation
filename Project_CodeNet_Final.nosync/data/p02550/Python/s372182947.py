N, X, M = map(int, input().split())
ls = [False]*M
ls_mod = []
x = X
for m in range(M+1):
  if ls[x] == False:
    ls_mod.append(x)
    ls[x] = m
    x = (x**2)%M
  else:
    last = m
    fast = ls[x]
    diff = last - fast
    break
if M == 1:
  print(0)
else:
  if last > N:
    print(sum(ls_mod[:N]))
  else:
    shou = (N-fast) // diff
    amari = (N-fast) % diff
    print(sum(ls_mod[:fast])+sum(ls_mod[fast:])*shou+sum(ls_mod[fast:fast+amari]))

