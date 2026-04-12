N = int(input())
S = input()
K = int(input())
a = S[K-1]
for i in range(N):
  if S[i] != a:
    S = S.replace(S[i], '*')
    
print(S)