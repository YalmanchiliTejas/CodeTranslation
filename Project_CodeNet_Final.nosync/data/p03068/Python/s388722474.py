n = int(input())
s = input()
k = int(input())

t = s[k-1]
ans = ''
for i in range(len(s)):
    if s[i] == t:
        ans += s[i]
    else:
        ans += '*'
print(ans)
