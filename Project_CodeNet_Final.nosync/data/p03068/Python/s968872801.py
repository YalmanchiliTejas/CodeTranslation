N = int(input())
S = input()
K = int(input())

ns = ""
for s in S:
    if s != S[K-1]:
        ns += "*"
    else:
        ns += s

print(ns)