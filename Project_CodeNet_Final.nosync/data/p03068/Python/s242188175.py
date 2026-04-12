n = int(input())
s = input()
k = int(input())

p = s[k-1]
ans = str()

for i in range(n):
    if s[i] != p:
        ans += "*"
    else:
        ans += s[i]

print(ans)