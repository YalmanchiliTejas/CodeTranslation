N = int(input())
S = input()
K = int(input())
result = []
for i in range(N):
  if S[K-1] != S[i]:
    result.append("*")
  else:
    result.append(S[i])
print("".join(result))