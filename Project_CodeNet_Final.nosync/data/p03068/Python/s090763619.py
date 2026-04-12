n = int(input())
s = input()
k = int(input())
ans = ''
for i in range(n):
    if s[i] != s[k - 1]:
        ans += '*'
    else:
        ans += s[i]
print(ans)
