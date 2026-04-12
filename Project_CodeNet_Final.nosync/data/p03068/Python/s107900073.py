N = int(input())
S = input()
K = int(input())
target = S[K-1]

for s in S:
  if s not in [target]:
    print('*', end='')
  else:
    print(s, end='')