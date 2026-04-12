n=int(input())
s=input()
k=int(input())
ans=[]
for i in range(n):
    if s[i]==s[k-1]:
        t=s[i]
    else:
        t="*"
    ans.append(t)
print(*ans,sep="")