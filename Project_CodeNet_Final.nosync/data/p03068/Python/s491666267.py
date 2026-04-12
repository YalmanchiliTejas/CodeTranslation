n = int(input())
s = input()
k = int(input())
a = s[k-1]
s = list(s)
for i in range(len(s)):
        if s[i] != a:
                s[i] = "*"

for i in range(len(s)):
        print(s[i], end='')