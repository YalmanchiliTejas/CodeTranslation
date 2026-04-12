s = input()
ans = 'No'
pre = s[0]
for i in s[1:]:
    if pre != i:
        ans = 'Yes'
        break
print(ans)