N = int(input())
S = input()
K = int(input())
for _ in S: print(_ if _==S[K-1] else "*", end="")