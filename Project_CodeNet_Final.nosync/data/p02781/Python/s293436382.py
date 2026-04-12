def almost0(m,K):
    M=str(m)
    s=len(M)
    if s<K:
        return 0
    elif m==0:
        return 0
    elif K==0:
        return 0
    elif K==1:
        return int(M[0])+almost0((10**(len(M)-1))-1,K)
    elif K==2:
        return (int(M[0])-1)*9*(len(M)-1)+almost0(m%(10**(len(M)-1)),K-1)+almost0((10**(len(M)-1))-1,K)
    else:
        return  (int(M[0])-1)*81*(s-1)*(s-2)//2+almost0(m%(10**(s-1)),K-1)+almost0((10**(s-1))-1,K)

N=int(input())
K=int(input())

print(almost0(N,K))