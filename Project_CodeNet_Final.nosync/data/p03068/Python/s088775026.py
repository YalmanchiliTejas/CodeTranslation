N = int(input())
S = input()
K = int(input()) -1

c = S[K]

l = ""

for d in S:
    if d == c:
        l = l + d
    else:
        l = l + "*"

print(l)