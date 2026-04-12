n = int(input())
s = list(input().strip())
k = int(input())

change = s[k-1]
for i in range(n):
    if s[i] != change:
        s[i] = "*"

print("".join(s))
