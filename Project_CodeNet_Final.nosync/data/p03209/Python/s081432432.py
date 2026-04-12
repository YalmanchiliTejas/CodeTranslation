l=[[2**(2+i)-3,2**(1+i)-1] for i in range(51)]
N,X=map(int,input().split())
a=0
def k(n,x):
    global a
    if x==l[n][0]:
        return l[n][1]
    elif l[n-1][0]+1<x:
        return l[n-1][1]+k(n-1,x-l[n-1][0]-2)+1
    elif 1<=x:
        return k(n-1,x-1)
    else:
        return 0
print(k(N,X))