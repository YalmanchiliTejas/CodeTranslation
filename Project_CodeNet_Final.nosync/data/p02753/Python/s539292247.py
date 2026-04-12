s = input()
ans = 'No'
if s[0] != s[1] or s[1] != s[2] or s[2] != s[0]:
    ans = 'Yes'
print(ans)