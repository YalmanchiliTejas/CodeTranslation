n = int(input())
s = input()
k = int(input())

error = s[k-1]

ans = ""
for i in range(n):
    if s[i] != error:
        ans += "*"
    else :
        ans += s[i]
print(ans)