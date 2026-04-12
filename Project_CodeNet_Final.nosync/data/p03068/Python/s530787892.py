n = int(input())
s = input()
k = int(input())
ans = ""

x = s[k - 1]

for i in range(n):
    if s[i] == x:
        ans = ans + s[i]
    else:
        ans = ans + "*"

print(ans)