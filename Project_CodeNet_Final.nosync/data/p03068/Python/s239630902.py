n = int(input())
s = input()
rename = int(input())
dum = s[rename-1]
ans = ""
for i in range(n):
    if s[i] == dum:
        ans += dum
    else:
        ans += "*"
print(ans)