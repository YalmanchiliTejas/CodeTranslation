N, S, K = open(0).read().split()
N = int(N)
K = int(K)
ck = S[K - 1]
ans = [c if c == ck else "*" for c in list(S)]
print("".join(ans))                  