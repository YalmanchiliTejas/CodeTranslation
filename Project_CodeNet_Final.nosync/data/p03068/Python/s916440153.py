n = int(input())
s = input()
k = int(input())
rep = s[k-1]
ans = ""
for i in range(n):
    if s[i] != rep:
        ans += "*"
    else:
        ans += s[i]
print(ans)
