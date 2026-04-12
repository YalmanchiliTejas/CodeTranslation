N = int(input())
S = input()
K = int(input())

sk = S[K-1]

print("".join([s if s == sk else "*" for s in S]))