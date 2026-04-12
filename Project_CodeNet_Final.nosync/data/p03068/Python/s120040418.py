N = int(input())
S = input()
K = int(input())

K_new = K - 1
i = 0

for i in range(0,N):
    if S[i] != S[K_new]:
        print("*", end="")
        i += 1
    else:
        print(S[i], end="")
        i += 1