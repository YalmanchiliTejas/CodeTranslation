from collections import Counter
N = int(input())

S = []
for i in range(N):
  S.append(list(input()))
T = Counter(S[0])
for i in range(1,N):
  T &= Counter(S[i])

s =""
for k in sorted(list(T)):
  s += k * T[k]
print (s)