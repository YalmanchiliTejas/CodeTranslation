n = int(input())
s = input()
k = int(input())

t = s[k-1]
ans = ""
for i in s:
    if i != t:
        ans+="*"
    else:
        ans+=t
print(ans)