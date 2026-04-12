N,M=map(int,input().split())

his=[False]*N

A=[[0]*2 for i in range(M)]
for i in range(M):
    a,b=map(int,input().split())
    A[i][0],A[i][1] =a-1,b-1

def search(now,his,A):
    
    if all(his):
        return 1
    
    else:
        cnt=0
        for a in A:
            if now in a:
                nex=a[(a.index(now)+1)%2]
                if not his[nex]:
                    his[nex]=True
                    cnt+=search(nex,his,A)
                    his[nex]=False
       
        return cnt

his[0]=True
print(search(0,his,A))