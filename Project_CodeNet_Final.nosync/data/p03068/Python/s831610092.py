n = int(input())
s = input()
k = int(input())

res = ""

for i in s:
    if i == s[k - 1]:
        res += i
    else:
        res += "*"
print(res)