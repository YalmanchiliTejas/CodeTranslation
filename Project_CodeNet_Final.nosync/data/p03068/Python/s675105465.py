n = int(input())
s = list(input())
k = int(input())

S = s[k-1]

for i in range(n):
    if s[i] != S:
        s[i] = "*"

print(*s, sep="")