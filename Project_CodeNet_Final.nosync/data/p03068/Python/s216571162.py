N = int(input())
S = str(input())
S = list(S)
K = int(input())


for i in range(N):
      if S[i] != S[K-1]:
            S[i] = '*' 

print(''.join(S))

