def calc(x):
    global mount
    global list
    count=0
    for y in range(1,x+1):
        if mount[x] >= mount[x-y]:
            count+=1
    if x == count:
        list.append(x)

N=int(input())

mount=list(map(int, input().split()))

list=[]

for z in range(1,len(mount)):
    calc(z)

print(1+len(list))