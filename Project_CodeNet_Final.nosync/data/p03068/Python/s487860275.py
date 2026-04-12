N = int(input())
S = input()
K = int(input())

s = list(S)

for i in range(len(s)):
    if s[i] != s[K - 1]:
        s[i] = '*'

S = "".join(s)

print(S)
