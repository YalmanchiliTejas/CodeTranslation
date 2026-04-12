n = int(input())
s = input()
k = int(input())

c = s[k-1]

ans = ''
for m in s:
    if m != c:
        ans += '*'
    else:
        ans += c
print(ans)