N = int(input())
S = input()
K = int(input())
X = S[K-1]
SS = list(S)
for i in range(len(SS)):
  if SS[i] != X:
    SS[i] = '*'
a = ''.join(SS)
print(a)
    