n = int(input())
s = input()
k = int(input())

c = s[k - 1]
ans = ''
for ci in s:
    if ci == c:
        ans += c
    else:
        ans += "*"

print(ans)
