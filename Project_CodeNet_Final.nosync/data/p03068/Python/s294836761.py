n=int(input())
s=input()
k=int(input())
sk=s[k-1]
ans=""
for i in range(n):
    if s[i]!=sk:
        ans+="*"
    else:
        ans+=s[i]
    
print(ans)