N = int(input())
S = input()
K = int(input())

tag = S[K-1]
for n in range(N):
    if S[n] != tag:
        S = S[:n] + '*' + S[n+1:]

print(S)