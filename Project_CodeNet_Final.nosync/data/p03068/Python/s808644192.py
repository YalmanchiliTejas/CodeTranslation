N = int(input())
S = input()
K = int(input())
S = list(S)
e = S[K-1]
for i in range(N):
    if S[i] == e:
        continue
    S[i] = '*'
print(''.join(S))
