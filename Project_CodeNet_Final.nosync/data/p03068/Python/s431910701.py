N = int(input())
S = input()
K = int(input())
A = [""] * N

c = S[K-1]

for i in range(N):
  if S[i] == c:
    A[i] = c
  else:
    A[i] = "*"
    
print("".join(A))