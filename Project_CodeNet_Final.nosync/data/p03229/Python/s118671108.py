def point(arr):
    res=0
    for i in range(1,N):
        res+=abs(arr[i]-arr[i-1])
    return res
def merge(li_1,li_2):
    arr=[]
    for i in range(N):
        if not i%2:
            arr.append(li_2[i//2])
        else:
            arr.append(li_1[i//2])
    return arr

N=int(input())
A=[int(input()) for i in range(N)]
A.sort()
if not N%2:
    ans=0
    l,r=A[:N//2],A[N//2:]
    print(point(merge(l,r)))
else:
    ans=-1
    li=[]
    l,r=A[:N//2],A[N//2:]
    r[1],r[-1]=r[-1],r[1]
    ans=max(ans,point(merge(l,r)))
    li=[]
    l,r=A[:N//2+1],A[N//2+1:]
    l[0],l[-2]=l[-2],l[0]
    ans=max(ans,point(merge(r,l)))
    print(ans)