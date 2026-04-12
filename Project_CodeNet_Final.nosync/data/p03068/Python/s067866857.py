N = int(input())
S = input()
K = int(input())

for i in range(0,N):
    if S[i] != S[K-1]:
        S = S.replace(S[i], "*")
print(S)