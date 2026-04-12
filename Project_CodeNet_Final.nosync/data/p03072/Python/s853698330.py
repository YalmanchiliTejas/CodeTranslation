x  = int(input())
lis = list(map(int,input().split()))
it = 0
count = 0
for i in range(len(lis)):
    for j in range(len(lis)-i):
   	    if lis[len(lis)-1-i]>=lis[len(lis)-1-j-i]:
   	        it = it + 1
   	    else:
   	        break
    if it==(len(lis)-i):
        count+=1
    it = 0    
print(count)    