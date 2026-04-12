n,x=list(map(int,input().split()))

def rec(lev,x):
    bottom=1
    center=2**(lev+1)-1
    top=2**(lev+2)-3


    if x>center:
        if top==x:
            return 2**(lev+1)-1
        return 2**lev+rec(lev-1,x-center)
    elif x==center:
        return 2**lev
    else:
        if bottom==x:
            return 0
        
        return rec(lev-1,x-1)

print(rec(n,x))