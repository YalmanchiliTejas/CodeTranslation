n = int(input())
s = input()
k = int(input())
ans = ""
for data in s:
    if data == s[k-1]:
        ans += s[k-1]
    else:
        ans += "*"
print(ans)