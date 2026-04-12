N = int(input())
S = input()
K = int(input())

char = S[K-1]

O = []
for i in range(N):
  if S[i] != char:
    O.append('*')
  else:
    O.append(char)
print(''.join(O))
