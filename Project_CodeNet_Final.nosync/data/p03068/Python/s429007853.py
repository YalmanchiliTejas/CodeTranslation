N = int(input())
S = input()
K = int(input())

T = S[K-1]
res = [s if s==T else "*" for s in S]
print("".join(res))
