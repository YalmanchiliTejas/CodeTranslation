n = int(input())
s = input()
k = int(input())

target = s[k-1]

ans = ""
for i in s:
    if i == target:
        ans += i
    else:
        ans += "*"
print(ans)
