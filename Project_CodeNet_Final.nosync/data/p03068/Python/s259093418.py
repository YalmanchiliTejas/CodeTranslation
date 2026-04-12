n = int(input())
s = list(input())
k = int(input())
for i in range(n):
    if s[k - 1] != s[i]:
        s[i] = "*"
print("".join(s))