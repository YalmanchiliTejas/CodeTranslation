size=int(input())
mountain=input().split()
count=0
highest=0
for i in range(0,size):
    if(int(mountain[i])>=highest):
        count+=1
        highest=int(mountain[i])
    else:
        continue
print(count)