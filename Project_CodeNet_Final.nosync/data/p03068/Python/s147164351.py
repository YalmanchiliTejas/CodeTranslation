N = int(input())
S = list(input())
K = int(input())

key = S[K-1]

for i in range(len(S)):
    if not S[i] == key:
        S[i] = '*'

print(''.join(S))
