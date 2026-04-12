n = int(input())
s = input()
k = int(input())

ans = ""

ch = s[k-1]

for c in s:
    if c == ch:
        ans+=ch
    else:
        ans+="*"

print(ans)