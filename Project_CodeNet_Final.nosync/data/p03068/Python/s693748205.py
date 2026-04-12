N = input()
S = input()
K = int(input())

for i in S:
  if i != S[K-1]:
    S = S.replace(i,"*")
print(S)