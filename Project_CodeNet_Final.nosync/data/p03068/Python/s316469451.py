N = int(input())
S = list(str(input()))
K = int(input())

SK = str(S[K-1])
for i in range(0,N):
    if S[i] == SK:
        pass
    else:
        S[i] = '*'
for j in S:
  print(j, end ="")