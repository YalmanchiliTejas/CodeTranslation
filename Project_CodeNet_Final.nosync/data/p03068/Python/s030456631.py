N = int(input())
S = list(input())
K = int(input())

S_k = S[K-1]

ans = []

for i in range(len(S)):
  if S[i] != S_k:
    ans.append('*')
  else:
    ans.append(S[i])
print(''.join(ans))