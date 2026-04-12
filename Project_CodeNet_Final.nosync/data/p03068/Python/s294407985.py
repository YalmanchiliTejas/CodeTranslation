N = int(input())
S = input()
K = int(input())
T = ['']*N
letter = S[K-1]
for i in range(N):
  if S[i] == letter:
    T[i] = S[i]
  else:
    T[i] = "*"
print(''.join(T))   