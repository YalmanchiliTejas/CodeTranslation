import bisect
N=int(input())

alist=[]
for i in range(N):
  alist.append(int(input()))
#print(alist)

color_list=[alist.pop()]
for i in reversed(range(N-1)):
  a=alist[i]
  if a>=color_list[-1]:
    #insert to tail
    color_list.append(a)
  else:
    #replace
    pos=bisect.bisect(color_list,a)
    color_list[pos]=a
  #print(color_list)
  
print(len(color_list))