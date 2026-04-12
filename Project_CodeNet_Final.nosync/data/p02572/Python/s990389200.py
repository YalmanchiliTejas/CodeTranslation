mod=10**9+7
def power(x, y):
    if   y == 0     : return 1
    elif y == 1     : return x % mod
    elif y % 2 == 0 : return power(x, y//2)**2 % mod
    else            : return power(x, y//2)**2 * x % mod
def mul(x,y):
  return (x%mod)*(y%mod)%mod
def add(x,y):
  return (x+y)%mod

n=int(input())
alist=list(map(int,input().split()))
s=sum(alist)%mod
print(mul(add(mul(s,s),-sum(mul(a,a) for a in alist)),power(2,mod-2)))