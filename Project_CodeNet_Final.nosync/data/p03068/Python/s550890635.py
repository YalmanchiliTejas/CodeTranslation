n = int(input())
s = input()
k = int(input())

t = s[k-1]
ans = ""
for ch in s:
    if ch == t:
        ans+=t
    else:
        ans+="*"

print(ans)