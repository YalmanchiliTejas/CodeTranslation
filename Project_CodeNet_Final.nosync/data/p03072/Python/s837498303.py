n = int(input())
a = list(map(int,input().split()))
m,cnt = a[0],1
for i in range(1,n):
    if m<=a[i]:
        cnt+=1
        m=a[i]
print(cnt)