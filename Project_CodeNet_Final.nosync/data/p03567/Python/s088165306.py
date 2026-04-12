s=list(input())
l=len(s)
ans="No"
for i in range(l-1):
    if(s[i]=="A" and s[i+1]=="C"):
        ans="Yes"
print(ans)