N = int(input())
S = list(input())
K = int(input())

target = S[K - 1]
converted = []
for c in S:
    if c != target:
        c = "*"
    converted.append(c)
print("".join(converted))