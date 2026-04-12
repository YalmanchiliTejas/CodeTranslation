N = int(input())
S = list(input())
K = int(input())
for i in range(N):
  if S[i] != S[K - 1]:
    print('*', end = '')
  else:
    print(S[i], end ='')