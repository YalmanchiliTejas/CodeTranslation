n = int(input())
s = input()
k = int(input())

target_cha = s[k - 1]

ans = ""
for c in s:
    if not c == target_cha:
        ans += "*"
    else:
        ans += c

print(ans)
