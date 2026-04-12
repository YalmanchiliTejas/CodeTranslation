s = input().rstrip()

t = s[0]
ans = 'No'
for i in range(len(s)):
    if s[i] != t:
        ans = 'Yes'

print(ans)