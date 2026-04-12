n=int(input())
s=input()
k=int(input())
ans=""
for i in range(n):
    if s[k-1]==s[i]:
        ans+=s[i]
    else:
        ans+="*"
print(ans)
