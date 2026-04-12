N, S, K = int(input()), list(input()), int(input())

S_new = "".join(["*" if S[i] != S[K-1] else S[i] for i in range(N)])

print(S_new)