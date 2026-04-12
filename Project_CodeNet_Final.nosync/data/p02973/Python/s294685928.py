def bis(l,target,start, end):
    while(start<end):
        mid = (start + end )//2
        if target > l[mid]:
            end = mid
        else:
            start = mid + 1
    return start

l = []
n = int(input())
for i in range(n):
    x = int(input())
    if l == []:
        l.append(x)
    else:
        idx = bis(l,x,0,len(l)-1)
        #print(l)
        #print(x,idx)
        if x > l[idx]:
            l[idx] = x
        else:
            l.append(x)
#print(l)
print(len(l)) 
