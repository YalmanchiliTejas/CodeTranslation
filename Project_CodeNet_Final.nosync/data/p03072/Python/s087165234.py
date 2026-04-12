n=int(input())
h=input().split(" ")
count=0
total=1
for i in range(1,n):
    
    for j in range(0,i):
        if int(h[i])>=int(h[j]):
            count+=1
    if(count==i):
        total+=1
    count=0
print(total)