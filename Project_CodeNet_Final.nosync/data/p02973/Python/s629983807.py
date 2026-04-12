n=int(input())
a=[int(input()) for _ in [0]*n]
temp=[]
cnt=0
import bisect
for i in range(n):
    b=bisect.bisect(temp,-a[i])
    if b==cnt:
        temp.append(-a[i])
        cnt+=1
    else:
        temp[b]=-a[i]
print(len(temp))