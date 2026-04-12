n = int(input())
a = list(map(int, input().split()))
i = 0
tmp = 0
tmpura = 0
while(i < n):
    tmp += a[i]
    i+=1
tmp=tmp **2
i = 0
while (i < n):
    tmpura += a[i]**2
    i+=1
tmpura=tmpura
ans = ((tmp - tmpura)//2)%(10**9+7)
print(ans)