n = int(input())
s = input()
k = int(input())
q = s[k-1]
ans = ""
for a in s:
    if a != q:
        ans = ans + "*"
    else:
        ans = ans + s[k-1]

print(ans)