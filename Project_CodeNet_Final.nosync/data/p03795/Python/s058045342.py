a=int(input())
total=0
count=0
for i in range(a):
    total+=800
    count+=1
    if count%15==0:
        total-=200
print(total)