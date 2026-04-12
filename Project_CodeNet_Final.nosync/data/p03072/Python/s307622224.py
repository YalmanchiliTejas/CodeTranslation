n=int(input())
li=list(map(int,input().split()))
cnt=1
for i in range(1,len(li)):
    flag=True
    for j in range(0,i):
        if li[i]<li[j]:
            flag = False
    if flag :
        cnt +=1
print(cnt)