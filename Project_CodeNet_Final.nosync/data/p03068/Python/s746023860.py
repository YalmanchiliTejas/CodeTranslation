n = int(input())
S = list(input())
k = int(input())

for i in range(n):
  if S[i] != S[k-1]:
    S[i] = '*'
    
print("".join(S))