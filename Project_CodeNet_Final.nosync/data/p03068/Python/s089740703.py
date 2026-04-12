n = int(input())
s = input()
k = int(input())

res = ""
for i in range(n):
    if s[i] != s[k-1]:
        res += "*"
    else:
        res += s[i]
print(res)