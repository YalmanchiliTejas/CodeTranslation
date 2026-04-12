N = int(input())
S = input()
K = int(input())

c = S[K-1]
out = ""
for s in S:
    if s ==c:
        out += c
    else:
        out += "*"
print(out)