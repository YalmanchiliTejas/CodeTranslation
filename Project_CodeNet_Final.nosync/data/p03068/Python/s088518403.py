n = int(input())
s = str(input())
k = int(input())
c = s[k-1]
ans = ''
for x in s:
    if x == c:
        ans += x
    else:
        ans += '*'
print(ans)