ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

n = ii()
alis = []
for _ in range(n):
    ima = ii()
    ima *= -1
    alis.append(ima)

from bisect import bisect_left as bl
'''index  =  bl(list,num)'''

imaa = [1]*n
for i in range(n):
    index = bl(imaa,alis[i]+1)
    imaa[index] = alis[i]
index = bl(imaa,1)
print(index)

