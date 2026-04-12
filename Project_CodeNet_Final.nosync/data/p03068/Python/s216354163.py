n = int(input())
s = input()
k = int(input())

c = s[k-1]
ans = ""
for e in s:
    if e == c:
        ans += e
    else:
        ans += "*"

print(ans)
