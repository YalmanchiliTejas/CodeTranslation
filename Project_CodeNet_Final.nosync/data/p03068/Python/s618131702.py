N = int(input())
S = list(input())
K = int(input())

buff = S[K-1]
for i in range(len(S)):
    if buff != S[i]:
        S[i] = '*'

print("".join(S))