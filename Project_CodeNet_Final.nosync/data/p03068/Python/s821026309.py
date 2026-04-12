N = int(input())
S = input()
K = int(input())

s = S[K-1]

for i in S:
  if i == s:
    print(i, end='')
  else:
    print('*', end='')