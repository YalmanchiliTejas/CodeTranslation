n = int(input())
s = input()
k = int(input())
ch = s[k - 1]
ans = str()
for x in s:
    if x != ch:
        ans += "*"
    else:
        ans += ch
print(ans)