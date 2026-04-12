N = int(input())
S = input()
K = int(input())

s = list(S)

t = s[K - 1]

i = 0
for c in s:
    if t != c:
        s[i] = '*'
    i += 1

print(''.join(s))