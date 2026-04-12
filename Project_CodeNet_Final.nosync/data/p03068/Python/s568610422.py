N = int(input())
S_temp = input()
K = int(input())

S = [c for c in S_temp]

target = S[K-1]
for i in range(N):
  if S[i] != target:
    S[i] = '*'
print(*S, sep='')