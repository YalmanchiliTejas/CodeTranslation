s = list(input())
ans = 'No'
for i in range(len(s) - 1):
    if s[i: i + 2] == list('AC'):
        ans = 'Yes'
        break
print(ans)
