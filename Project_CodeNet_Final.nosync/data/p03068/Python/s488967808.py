n = int(input())
s = list(input())
k = int(input())
o = ""
x = s[k-1]
for i in s:
    if i != x:
        i = "*"
        o += i
    else:
        o += i
print(o)