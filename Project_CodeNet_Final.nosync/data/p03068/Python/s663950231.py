import sys

N = int(input())
S = input()
K = int(input())

SS = []

for i in range(N):
  if S[i] == S[K-1]:
    SS.append(S[i])
  else:
    SS.append("*")
    
print(''.join(SS))
