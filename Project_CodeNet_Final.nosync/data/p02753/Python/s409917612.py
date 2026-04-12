s = list(input())
ans = "No"
prev = s[0]
for i in s[1:]:
    if i != prev:
        ans = "Yes"
        break
    prev = i
print(ans)
