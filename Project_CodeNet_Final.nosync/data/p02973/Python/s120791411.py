import bisect
N = int(input())
A = [int(input())for _ in range(N)]
li = [-1]
for i in A[::-1]:
    if(li[-1]<i):
        li.append(i)
    else:
        ind = bisect.bisect_right(li,i)
        if(ind>=len(li)):
            li.append(i)
        elif(li[ind]>i):
            li.pop(ind)
            li.insert(ind,i)
        else:
            li.pop(ind+1)
            li.insert(ind+1)
print(len(li)-1)