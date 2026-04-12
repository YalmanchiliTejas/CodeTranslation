n=int(input())
s=input()
k=int(input())

temp=s[k-1]
#print(temp)

ans=""
for i in range(n):
    if s[i] == temp:
        ans+=s[i]
    else:
        ans+="*"

print(ans)
