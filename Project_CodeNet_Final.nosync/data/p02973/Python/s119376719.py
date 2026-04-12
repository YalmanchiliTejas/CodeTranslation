n=int(input())
a=[int(input()) for _ in range(n)]

import bisect
#a=[0,2,3,4,67,8]
#a.sort()
#bisect.bisect_left(a, 4) #被ったら左側のindexを返す
#bisect.bisect_right(a, 4)#被ったら右側のindexを返す

color=[1]
lencolor=1
for aa in a:
    aa=-1*aa
    i=bisect.bisect_right(color, aa)
    if i==lencolor:
        color.append(aa)
        lencolor+=1
        #print("insert")
    else:
        color[i]=aa
        #print("update")
    #print(color,aa) 
print(lencolor)
