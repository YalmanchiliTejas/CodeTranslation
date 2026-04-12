n = int(input())
s = list(input())
k = int(input())

for i in range(len(s)):
    if s[i] != s[k - 1]:
        s[i] = "*"
ans = "".join(s)
print(ans)