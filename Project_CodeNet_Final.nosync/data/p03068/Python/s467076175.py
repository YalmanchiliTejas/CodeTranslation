n = int(input())
s = input()
index = int(input()) - 1
ans = ""
for c in s:
    if c != s[index]:
        ans += "*"
    else:
        ans += c
print(ans)