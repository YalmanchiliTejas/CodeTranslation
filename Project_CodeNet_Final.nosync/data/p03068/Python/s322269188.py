N = int(input())
S = input().strip()
K = int(input())
a = S[K-1]
for i in range(N):
    if S[i]!=a:
        S = S[:i]+"*"+S[i+1:]
print(S)