n = int(input())
s = input()
k = int(input())

c = s[k-1]
rs = ""
for e in s:
    if e == c:
        rs = rs + e
    else:
        rs = rs + '*'
print(rs)
