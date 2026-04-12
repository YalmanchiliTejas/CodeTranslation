n = int(input())
s = list(input().strip())
k = int(input())-1
for i, v in enumerate(s):
    if s[i] != s[k]:
        s[i] = '*'

print("".join(s))
