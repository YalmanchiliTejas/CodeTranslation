n = int(input())
hn = list(map(int,input().split()))
m = 0
ans=0
for i in hn:
    if i >= m:
        ans+=1
        m = i
print(ans)