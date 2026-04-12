n = int(input())
s = list(map(str, input()))
k = int(input())

for i in range(len(s)):
    if s[i] != s[k-1]:
        s[i] = "*"

out = ''.join(s)
print(out)