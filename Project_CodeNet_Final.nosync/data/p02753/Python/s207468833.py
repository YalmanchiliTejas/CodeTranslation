S = input()
before = S[0]
n = 0

for s in S:
    if before == s:
        n += 1

if n == 3:
    print('No')
else:
    print('Yes')
