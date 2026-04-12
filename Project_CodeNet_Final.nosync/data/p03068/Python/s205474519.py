n = int(input())
s = input()
a = int(input())
ans = ""
for i in range(n):
    if s[i] == s[a - 1]:
        ans += s[i]
    else:
        ans += "*"
print(ans)