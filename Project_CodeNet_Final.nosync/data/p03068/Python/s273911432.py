n = int(input())
s = list(input())
k = int(input())

mozi = s[k-1]

for i in range(n):
    if s[i] != mozi:
        s[i] = "*"

print(*s, sep="")
