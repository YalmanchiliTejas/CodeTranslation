N=int(input())
H=list(map(int,input().split()))
count=0
flag=1
for i in range(N):
    flag=1
    for j in range(i):
        if H[i]<H[j]:
            flag=0
            break
    if flag==1:
        count+=1
print(count)