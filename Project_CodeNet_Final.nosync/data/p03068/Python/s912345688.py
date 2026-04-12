N = int(input())
S = input()
K = int(input())

c = S[K-1]

l = ""
for s in S:
    if s == c:
        l += c
    else:
        l += "*"

print(l)
