s = list(input())

ans = "No"
a = s[0]
for i in s[1:]:
    if a != i:
        ans = "Yes"
    a = i

print(ans)