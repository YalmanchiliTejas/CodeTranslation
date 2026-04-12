N = int(input())
S = list(input())
K = int(input())

a = S[K-1]

for i in range(N):
    if S[i] != a:
        print("*", end="")
    else:
        print(S[i], end="")

print()
