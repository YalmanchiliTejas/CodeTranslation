import bisect
N=int(input())
A=[]
ans=0
for i in range(N):
    a=int(input())
    A.append(a)
cl=[A[-1]]
ans=1
for i in range(N-1)[::-1]:
    a=A[i]
    if a>=cl[-1]:
        cl.append(a)
        ans+=1
    else:
        b=bisect.bisect_right(cl,a)
        cl[b]=a
print(ans)