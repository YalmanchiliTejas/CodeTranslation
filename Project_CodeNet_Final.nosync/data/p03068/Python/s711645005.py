N = int(input())
S = input()
K = int(input())
ignore = S[K-1]

for c in [chr(i) for i in range(ord('a'), ord('z')+1)]:
    if c == ignore:
        continue
    S = S.replace(c, '*')

print(S)
