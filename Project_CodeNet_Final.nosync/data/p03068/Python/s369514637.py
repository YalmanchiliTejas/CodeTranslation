N, S, K = int(input()), input(), int(input())
res = "".join(['*' if s != S[K-1] else s for s in S])
print(res)
