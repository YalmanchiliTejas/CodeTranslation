N = int(input())
s = input()
S = [str(c) for c in s]
K = int(input())

for i in range(N):
    if str(S[i]) != str(S[K-1]):
        S[i] = "*"
i=0
for i in range(N):
    print(S[i], end="")

