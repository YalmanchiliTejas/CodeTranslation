n = int(input())
s = list(input())
k = int(input())-1

for i in range(len(s)):
    if s[i] != s[k]:
        s[i] = '*'

print("".join(s))