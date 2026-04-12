N = int(input())
S = str(input())
K = int(input())
K = K - 1
inc = 0

target = S[K]
for i in S:
    if not target == i:
        S = S.replace(S[inc], '*')
    inc += 1
print(S)