n = int(input())
s = list(input())
k = int(input())
dstr = s[k-1]
newS = ""
for i in s:
    if i != dstr:
        i = "*"
    newS += i
print(newS)