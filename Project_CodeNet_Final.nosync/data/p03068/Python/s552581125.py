n = int(input())
s = input()
k = int(input())
ans = ''
for i in s:
    ans += '*' if not s[k-1] == i else i

print(ans)