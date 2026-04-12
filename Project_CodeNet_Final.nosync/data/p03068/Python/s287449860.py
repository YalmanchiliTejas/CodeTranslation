N = int(input())
S = input()
K = int(input())

letter = S[K-1]

out = ''
for s in S:
    if s == letter:
        out += s
    else:
        out += '*'
print(out)
