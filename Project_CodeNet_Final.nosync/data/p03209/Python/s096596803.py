N,X=map(int,input().split())
A=[2**(i+2)-3 for i in range(0,N+1)]
pati=[2**(i+1)-1 for i in range(0,N+1)]
def function(num,level):
    if level==0:
        if num==1:
            return 1
        else:
            return 0
    elif num==1:
        return 0
    else:
        subslice=A[level-1]
        if subslice+1>=num:
            return function(num-1,level-1)
        elif num==subslice+2:
            return pati[level-1]+1
        elif A[level]-1>=num:
            return pati[level-1]+1+function(num-subslice-2,level-1)
        else:
            return pati[level]
print(function(X,N))
