N = int(input())
S = list(input())
K = int(input())

for i in range(N):
  if S[i] == S[K-1]:
    continue
  else:
    S[i] = '*'
    
print(''.join(S))