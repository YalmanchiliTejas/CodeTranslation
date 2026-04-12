N = input()
K = input()

def fact(x):
  r = 1
  while x>0:
    r *= x
    x -= 1
  return r

def comb(x, y):
  if y>x:
    return 0
  return fact(x)/fact(y)/fact(x-y)

N = str(N+1)
def f(d, k):
  if k==0:
    if d>=len(N) or int(N[d:])==0:
      return 0
    else:
      return 1
  while d<len(N) and N[d]=="0":
    d += 1
  if d>=len(N):
    return 0
  return (
    comb(len(N)-d-1, k)*9**k +
    (int(N[d])-1)*comb(len(N)-d-1, k-1)*9**(k-1) +
    f(d+1, k-1))

print f(0, K)
