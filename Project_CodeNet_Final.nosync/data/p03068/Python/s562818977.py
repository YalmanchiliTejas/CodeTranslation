N = int(input())
S = input()
K = int(input())

target = S[K-1]

a = ''
for c in S:
    if c != target:
        a += '*'
    else:
        a += c
print(a)