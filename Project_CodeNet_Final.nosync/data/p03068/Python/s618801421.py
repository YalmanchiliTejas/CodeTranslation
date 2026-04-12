n = int(input())
s = input()
k = int(input())
t = s[k - 1]
r = ""
for i in s:
    if i == t:
        r = r + i
    else:
        r = r + "*"

print(r)