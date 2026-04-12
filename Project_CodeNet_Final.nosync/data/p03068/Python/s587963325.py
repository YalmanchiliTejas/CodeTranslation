n = int(input())
S = list(input())
k = int(input())
s = S[k-1]
for i in range(n):
  if S[i] != s:
    S[i] = '*'

print(''.join(S))
