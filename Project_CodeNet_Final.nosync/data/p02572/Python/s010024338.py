#標準入力
N = int(input())
A = list(map(int, input().split()))

#累積和
S = [0]*N
for n in range(N):
  S[n] = S[n-1] + A[n]

_sum = int(0)
for i in range(N-1):
  _sum = _sum + (A[i] * (S[-1] - S[i]))

#modulo
_sum = _sum % (1000000000+7)
  
print(_sum)