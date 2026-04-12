N = int(input())
S = input()
K = int(input())
for i in range(N):
    if S[i] != S[K-1]:
        S = S[:i] + '*' + S[(i+1):]
print(S)