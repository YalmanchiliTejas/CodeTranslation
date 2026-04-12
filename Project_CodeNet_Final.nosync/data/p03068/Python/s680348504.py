N = int(input())
S = list(input())
K = int(input())

check = S[K-1]

for i in range(N):
  if S[i] != check:
    S[i] = '*'
    
print(''.join(S))