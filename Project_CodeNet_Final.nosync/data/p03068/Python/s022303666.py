N = int(input().rstrip())
S = input().rstrip()
K = int(input().rstrip())
for i in S:
  print(i if i == S[K-1] else '*', end="")
print()