n = int(input())
k = int(input())
s = str(n)
d = len(s)
c = 0
if k == 1:
  c += 9*(d-1)
if k == 2:
  c += 9*9*(((d-1)*(d-2))//2)
if k == 3:
  c += 3*9*9*(((d-1)*(d-2)*(d-3))//2)
if k == 1:
  c +=  int(s[0])
  print(c)
  exit()
if k == 2:
  s0 = int(s[0])
  c += (s0-1)*9*(d-1)
  for i in range(1,d):
    if int(s[i]) != 0:
      si = int(s[i])
      c += si + 9*(d-i-1)
      break
  print(c)
  exit()
if k == 3:
  s0 = int(s[0])
  c += (s0-1)*9*9*((d-1)*(d-2)//2)
  mi = 0
  for i in range(1,d):
    if int(s[i]) != 0:
      si = int(s[i])
      c += (si-1)*9*(d-i-1)+9*9*(d-i-1)*(d-i-2)//2
      mi = i
      break
  if mi != 0:
    for j in range(mi+1,d):
      if int(s[j]) != 0:
        sj = int(s[j])
        c += sj + 9*(d-j-1)
        break
  print(c)
  exit()