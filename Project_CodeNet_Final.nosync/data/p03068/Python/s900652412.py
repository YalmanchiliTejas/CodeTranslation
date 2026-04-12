n = int(input())
s = input()
k = int(input())
ans = ""
for c in s:
    if c == s[k-1]:
        ans = ans + c
    else:
        ans = ans + "*"
print(ans)
