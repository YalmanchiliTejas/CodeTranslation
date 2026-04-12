n = int(input())
S = list(input() for i in range(n))
alpha = "abcdefghijklmnopqrstuvwxyz"
B = [[0]*n for i in range(26)]
for i in range(n):
    s = S[i]
    for c in s:
        p = alpha.index(c)
        B[p][i] += 1
for i in range(26):
    for j in range(min(B[i])):
        print(alpha[i],end="")
print()