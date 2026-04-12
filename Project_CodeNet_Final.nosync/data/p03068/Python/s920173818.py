N = int(input())
S = input()
K = int(input())

s = list(S)
s1 = s[K-1]
for i in range(N):
    if s[i] != s1:
        S = S.replace(s[i], "*")

print(S)

