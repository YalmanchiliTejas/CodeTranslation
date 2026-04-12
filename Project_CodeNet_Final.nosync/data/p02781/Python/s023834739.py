N = input()
n = int(N)
l = len(N)
k = int(input())
ans = 0
tmp = 0
def c(x,y):
  z = 1
  for w in range(y):
    z *= x - w
    z /= y - w
  return z
#print(c(5,2))
for i in range(l):
  for d in range(10):
    if d < int(N[i]):
      if d == 0 and k - tmp >= 0:
        now = c(l-1-i,k-tmp) * 9**(k-tmp)
        ans += now
        #print(i,d,now,l-1-i,k-tmp)
      elif k - tmp - 1 >= 0:
        now =  c(l-1-i,k-tmp-1) * 9**(k-tmp-1)
        ans += now
        #print(i,d,now,l-1-i,k-tmp-1)
    elif d == int(N[i]):
      if d != 0:
        tmp += 1
if k == tmp:
  ans += 1
print(int(ans))