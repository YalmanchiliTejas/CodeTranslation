n = int(input())
s = input()
k = int(input())

c = s[k - 1]
ans = ''
for l in s:
    if l != c:
        ans += '*'
    else:
        ans += c
print(ans)
