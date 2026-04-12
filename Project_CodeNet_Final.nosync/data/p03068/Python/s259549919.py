N = int(input())
S = [_ for _ in input()]
K = int(input())

ans = [_ if _ == S[K - 1] else "*" for _ in S]

print("".join(ans))