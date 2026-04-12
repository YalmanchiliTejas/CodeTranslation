N = int(input())
S = input()
K = int(input())

S = list(S)
k = S[K-1]
for i in range(N):
  if S[i] != k:
    S[i] = '*'
    
print(''.join(S))