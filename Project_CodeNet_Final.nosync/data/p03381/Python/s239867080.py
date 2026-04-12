def find(A):
    X=[(A[i],i) for i in range(len(A))]
    X=sorted(X)
    ans=[0]*len(X)
    p1=(len(A)-1)//2
    p2=len(A)//2
    #print(p1,p2)
    for i in range(len(X)):
        a,b=X[i]
        if i<p2:
            ans[b]=X[p2][0]
        else:
            ans[b]=X[p1][0]
    return ans
input()
A=[str(x) for x in find(list(map(int,input().strip().split(" "))))]
print("\n".join(A))