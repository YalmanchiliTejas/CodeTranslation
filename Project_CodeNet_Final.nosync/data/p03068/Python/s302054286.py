N = int(input())
S = input()
K = int(input())

sk = S[K-1]
out = ''

for s in S:
    if s != sk:
        out += '*'
    else:
        out += sk
print(out)