import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))  #空白あり


N = I()
A = LI()
mod = 10**9+7
s = sum(A)
s %= mod

a = s**2-sum(A[i]**2 for i in range(N))
a %= mod
a *= pow(2,mod-2,mod)
a %= mod

print(a)
