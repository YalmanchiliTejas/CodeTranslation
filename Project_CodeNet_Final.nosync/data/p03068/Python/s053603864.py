N = int(input())
S = input()
K = int(input())

ch = S[K-1]

r = ''
for si in S:
    if si == ch:
        r += si
    else:
        r += '*'

print(r)