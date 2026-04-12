def main():
    n,x,m=map(int,input().split())
    A=[]
    s=set()
    while True:
        A.append(x)
        s.add(x)
        x**=2
        x%=m
        if x==0:
            A.append(0)
            break
        if x in s:
            break
    #print(A)
    if n<=len(A):
        return sum(A[:n])
    if A[-1]==0:
        return sum(A)
    for idx,a in enumerate(A):
        if a==x:
            break
    l=len(A)-idx
    cycles=(n-idx)//l
    remain=(n-idx)%l
    #print(idx,l,cycles)
    s=sum(A[idx:])
    ans=sum(A[:idx])
    ans+=s*cycles
    ans+=sum(A[idx:idx+remain])
    return ans
    
if __name__=='__main__':
    print(main())