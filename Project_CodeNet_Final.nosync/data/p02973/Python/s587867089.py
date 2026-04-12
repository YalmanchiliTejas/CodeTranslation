#LIS
n=int(input())
lists=[0]*n
for i in range(n):
    lists[i]=int(input())
import bisect
counter=0
lislist=[lists[-1]]
for i in range(2,n+1):
    a=lists[-i]
    index=bisect.bisect_right(lislist,a)
    if index<len(lislist):
        lislist[index]=a

    elif index==len(lislist):
        lislist.append(a)

print(len(lislist))