n = input()
s = input()
k = int(input())

rep = s[k-1]
ans =''

for _s in s:
    if not _s == rep:
        ans = ans + '*'
    else:
        ans = ans + _s

print(ans)