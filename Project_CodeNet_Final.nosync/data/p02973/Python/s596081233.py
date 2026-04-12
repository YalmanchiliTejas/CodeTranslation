import bisect

n=int(input())
a1=int(input())
alist=[]
for al in range(n-1):
    alist.append(-2)
alist.append(a1)

for i in range(n-1):
    an=int(input())
    #print(alist,an)
    index = bisect.bisect_left(alist, an)
    alist[index-1]=an

#print(alist)
index = bisect.bisect_left(alist, -1)
#print(index)
print(len(alist)- index)