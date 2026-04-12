n,x,m = map(int, input().split())

chk = [0 for i in range(m)]
a = x
s = x
c = 0
ary = [x]
flg = False
while True:
  if c == n:
    break
  x = (x**2)%m
  s += x
  c += 1
  if chk[x]:
    flg = True
    break
  ary.append(x)
  chk[x] = c
if flg == False:
  print (sum(ary[:-1]))
  exit()
cyc = ary[chk[x]:]
l1 = len(cyc)
ss = ary[:chk[x]]
l2 = len(ss)
tot = sum(ss) + sum(cyc)*((n-l2)//l1) + sum(cyc[:((n-l2)%l1)])
print (tot)