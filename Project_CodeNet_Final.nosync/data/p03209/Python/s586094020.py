nn,x=map(int,input().split())
ns=[1 for i in range(51)]
nm=[1 for i in range(51)]
for i in range(1,51):
    ns[i]=2*ns[i-1]+3
    nm[i]=2*nm[i-1]+1
def np(n,w):
    if w==0:
        return 0
    elif n==1:
        if w==1:
            return 0
        elif w==2:
             return 1
        elif w==3:
            return 2
        else:
            return 3
    else:
        if ns[n]//2+1>w:
            return np(n-1,w-1)
        elif ns[n]//2+1==w:
            return nm[n-1]+1
        else:
            return np(n-1,w-ns[n-1]-2)+nm[n-1]+1
print(np(nn,x))