from itertools import combinations as com
def comb(a,b):
  if a == 0:
    return 1
  r = 1
  for i in range(b):
    r *= a
    a -= 1
  r = r // [1,2,6][b-1]
  return r
n = input()
nl = len(n)
k = int(input())
i = 0
c = 0
while i < nl:
  if i+1 >= nl:
    break
  if i+1 < k:
    pass
  else:
    if k == 1:
      c += 9
    elif k == 2:
      c += 81 * i
    else:
      c += 729 * (i*(i-1))//2
  i += 1
lis = []
if k == 1:
  for cur in range(1,10):
    cur = cur * 10**i
    lis.append(cur)
elif k == 2:
  for j in range(i):
    for k in range(1,10):
      for cur in range(1,10):
        cur = cur * 10**i + k * 10**j
        lis.append(cur)
else:
  for j,k in com(range(i),2):
    for l in range(1,10):
      for m in range(1,10):
        for cur in range(1,10):
          if cur < int(n[0]):
            c += 1
          else:
            cur = str(cur) + '0'*(i-k-1) + str(l) + '0'*(k-j-1) + str(m) + '0'*j
            if cur <= n:
              c += 1
n = int(n)
for i in lis:
  if i <= n:
    c += 1
print(c)