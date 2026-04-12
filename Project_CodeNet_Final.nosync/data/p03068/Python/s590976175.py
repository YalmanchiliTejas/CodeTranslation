N = int(input())
S = list(input())
K = int(input())

selected_s = S[K-1]

for i in range(N):
  if S[i] is not selected_s:
    s = "*"
    S[i] = "*"
print("".join(S))