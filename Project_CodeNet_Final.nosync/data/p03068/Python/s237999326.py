n = int(input())
s = input()
k = int(input())

x = s[k-1]
ans = ''
for i in range(len(s)):
    if s[i] == x:
        ans += s[i]
    else:
        ans += '*'

print (ans)
