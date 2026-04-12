N = int(input())
S = input()
K = int(input())

for i in range(N):
  print(S[i] if S[i] == S[K-1] else '*', end='')
print()