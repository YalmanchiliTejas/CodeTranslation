N = int(input())
S = input()
K = int(input())
M = str()
for i in range(N):
    if S[i] != S[K-1]:
        M= M +"*"
    else:
        M= M +S[i]
print(M)