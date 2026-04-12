N = int(input())
S = input()
K = int(input())

S = list(S)
x = S[K-1]
S_index = [i for i in range(N) if S[i] != x]

for j in S_index:
  S[j] = "*"
  
print("".join(S))