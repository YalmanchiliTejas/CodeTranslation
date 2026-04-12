n = int(input())
s = input()
k = int(input())

ans = ""
for (i, c) in enumerate(s):
    if c != s[k-1]:
        ans += "*"
    else:
        ans += c

print(ans)