n = int(input())
s = input()
k = int(input())
kstr = s[k-1]
res = ""
for i in range(len(s)):
    if s[i] != kstr:
        res += "*"
    else:
        res += kstr

print(res)
