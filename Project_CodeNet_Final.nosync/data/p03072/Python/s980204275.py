n=int(input())

m=list(input().split())
ans=1
max=[int(m[0])]
for i in range(1,n):
    if int(m[i])>=max[-1]:
        max.append(int(m[i]))
        ans+=1
print(ans)