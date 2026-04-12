N = int(input())
S = input()
X = int(input())
for i in range(N):
  if S[i] != S[X-1]:
    S = S[:i] + '*' + S[i+1:]
print(S)