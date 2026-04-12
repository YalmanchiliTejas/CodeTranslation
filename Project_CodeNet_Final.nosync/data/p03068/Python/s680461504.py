N = int(input())
S = input()
K = int(input())
c0 = S[K-1]
L = []
for i in range(N):
  c = S[i] if S[i] == c0 else "*"
  L.append(c)
print("".join(L))
