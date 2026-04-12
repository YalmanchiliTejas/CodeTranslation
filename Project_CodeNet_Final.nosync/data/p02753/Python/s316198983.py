s = list(input())
ans = 'No'
first_station = s[0]
for c in s:
    if first_station != c:
        ans = 'Yes'

print(ans)