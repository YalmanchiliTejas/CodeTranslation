n = int(input())
s = list(input())
k = int(input())
t = s[k - 1]
for i in range(len(s)):
    if s[i] != t:
        s[i] = '*'
print("".join(s))
