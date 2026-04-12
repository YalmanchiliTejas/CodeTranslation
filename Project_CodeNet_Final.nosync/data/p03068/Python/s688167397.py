N = int(raw_input())
S = list(raw_input())
K = int(raw_input())

hoge = S[K-1]

for i in range(N):

      if S[i] != hoge:
            S[i] = "*"

print("".join(S))
