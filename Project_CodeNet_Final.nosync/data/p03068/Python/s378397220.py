N = int(input())
S = input()
K = int(input())
re = ''

for s in S:
  if s == S[K-1]:
    re += S[K-1]
  else:
    re += '*'

print(re)
