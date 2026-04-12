n=int(input())
ms=list(map(int,input().split(" ")))
ans=1
for i in range(n-1):
    check=list(filter(lambda x:x>ms[i+1],ms[:(i+1)]))
    if len(check)==0:
        ans+=1
print(ans)