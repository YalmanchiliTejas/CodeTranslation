#15:50
n,m,k = list(map(int,input().split()))
mod = 10 ** 9 + 7
def inv(x):
  y = 1
  while x != 1:
    y *= mod//x+1
    y %= mod
    x -= mod%x
  return y
#print(inv(5))
ans = 1
for i in range(k-2):
  ans *= n*m-2-i
  ans %= mod
  ans *= inv(k-2-i)
  ans %= mod
#print(ans)
zsum = [0]
for i in range(1,max(n,m)):
  zsum.append(zsum[-1]+i)
#print(zsum)
ans1 = 0
for i in range(m):
  ans1 += zsum[i]
  ans1 += zsum[m-1-i]
  ans1 %= mod
ans1 *= n ** 2
ans1 %= mod
ans2 = 0
for j in range(n):
  ans2 += zsum[j]
  ans2 += zsum[n-1-j]
ans2 *= m ** 2
ans2 %= mod
ans *= ans1 + ans2
ans *= inv(2)
ans %= mod
#print(ans1)
#print(ans2)
print(ans)