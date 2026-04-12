n = int(input())
s = input()
k = int(input())
t = s[k - 1]
ans = ""
for si in s:
    if si == t:
        ans += si
    else:
        ans += "*"
print(ans)
