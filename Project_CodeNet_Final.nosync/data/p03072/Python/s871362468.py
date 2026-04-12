N=int(input())
H=list(map(int,input().split()))
flag=1
count=0
for i in range(N):
    for j in range(i):
        if H[j]>H[i]:
            flag=0
            break
        else:
            flag=1
    if flag==1:
        count=count+1

print(count)