s = list(input())
ans = 'Yes'
if s.count('A') == 3 or s.count('B') == 3:
    ans = 'No'
print(ans)