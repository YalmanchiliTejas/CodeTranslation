N=int(input())
yama=[]
count=1
yama= list(map(int,input().split()))
max=yama[0]
for x in range(1,N):
    if max<=yama[x]:
        count+=1
        max=yama[x]

print(count)