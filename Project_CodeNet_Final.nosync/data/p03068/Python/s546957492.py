N = int(input())
S = input()
K = int(input())
w = S[K-1]
tmp = []
for s in S:
    if s == w:
        tmp.append(s)
    else:
        tmp.append('*')

print(''.join(tmp))
