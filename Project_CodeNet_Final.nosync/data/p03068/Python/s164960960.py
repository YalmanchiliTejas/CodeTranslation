n = int(input())
s = str(input())
k = int(input())
x = s[k-1]
ans = ""
for i in range(n):
    if s[i] != x:
        ans += "*"
    if s[i] == x:
        ans += s[i]
print(ans)