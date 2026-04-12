N=int(input())
A=list(map(int, input().split()))
def calc_mod(n):
    return n %(10**9+7)
AA=list(map(calc_mod, A))
X=0
XX=0
for i in range(N-1):
  XX+=AA[N-i-1]
  X+=AA[N-i-2]*XX
  X=X%(10**9+7)
print(X)