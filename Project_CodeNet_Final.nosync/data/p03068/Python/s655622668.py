n = int(input())
s = input()
k = int(input())
a = s[k-1]
ans = ''
for b in s:
    if b == a:
        ans += b
    else:
        ans += '*'
print(ans)