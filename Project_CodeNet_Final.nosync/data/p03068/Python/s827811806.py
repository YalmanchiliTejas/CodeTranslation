n = int(input())
s = list(input())
k = int(input())
st = s[k-1]
for i in range(n):
    if s[i] != st:
        s[i] = "*"
for i in range(len(s)):
    print(s[i], end="")
print()