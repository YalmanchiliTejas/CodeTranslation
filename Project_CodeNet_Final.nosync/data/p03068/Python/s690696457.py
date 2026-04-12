N = int(input())
S = input()
K = int(input())
X = []
i = 0
for i in range(N):
    if S[i] == S[K - 1]:
        X.append(S[K - 1])
    else:
        X.append('*')
x = ''.join(X)
print(x)