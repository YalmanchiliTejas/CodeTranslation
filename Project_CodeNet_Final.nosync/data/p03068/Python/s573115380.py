n = input()
s = input()
k = int(input())
c = s[k-1]
res = ""
for i in range(len(s)):
    if s[i] == c:
        res+= c
    else:
        res += "*"
print(res)
