n = int(input())
s = input()
k = int(input())

s_k = s[k-1]
ans = ""
for i in range(len(s)):
    if s[i] != s_k:
        ans += "*"
    else:
        ans += s[i]
print(ans)