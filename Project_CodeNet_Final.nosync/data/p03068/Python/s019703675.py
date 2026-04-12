N = int(input())
S = input()
K = int(input())

target = S[K-1]


s = list(S)
for index in range(len(s)):
    if s[index] != target:
        s[index] = '*'

print("".join(s))
