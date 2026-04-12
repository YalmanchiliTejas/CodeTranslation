n = int(input())
s = str(input())
k = int(input())-1

c = s[k]

out = ""

for i in s:
    if i == c:
        out += i
    else:
        out += "*"

print(out)