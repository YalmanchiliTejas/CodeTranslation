N = int(input())
H=[int(x) for x in input().split()]
#for i in range(N):
#    nlist.append([int(x) for x in input().split()])
count=0
high=0
for i in H:
    if(high<=i):
        high=i
        count+=1
print(count)