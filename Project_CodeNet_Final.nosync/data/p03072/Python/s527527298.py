n=input()
a=list(map(int,input().split(" ")))
count=0
currMax=a[0]-1
for it in a:
    if(it >= currMax):
        count+=1
        currMax=it
print(count)
