n = int(input())
s = input()
k = int(input())
tmp = s[k-1]
res = ""
for i in s:
    if i == tmp:
        res += i
    else:
        res += "*"
print(res)
