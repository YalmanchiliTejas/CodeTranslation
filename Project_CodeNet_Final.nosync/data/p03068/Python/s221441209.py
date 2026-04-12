N = int(input())
S = input()
K = int(input())
not_error = S[K - 1]
print(*[s if s == not_error else "*" for s in S], sep="")
