n=int(input())
h=list(map(int,input().split()))
hmax=0
count=0
for i in range(n):
    if int(h[i])>=hmax:
        count+=1
        hmax=int(h[i])
print(count)