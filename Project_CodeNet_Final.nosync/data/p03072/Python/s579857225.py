def MAP(): return map(int,input().split())

n = int(input())
*h, = MAP()
ans=1
for i in range(1,n):
    flag = True
    for j in range(i-1,-1,-1):
        if h[j]>h[i]:
            flag=False
            break
    if flag:
        ans+=1

print(ans)