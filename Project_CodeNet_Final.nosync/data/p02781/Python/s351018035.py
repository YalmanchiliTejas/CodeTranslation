n=int(input())
k=int(input())

def f(n,k):
    l=[int(i) for i in str(n)]
    if n<100000:
        cnt=0
        for i in range(1,n+1):
            s=str(i)
            if len(s)-s.count('0')==k:
                cnt+=1
        return cnt
    else:
        if k==1:
            cnt=(len(l)-1)*9
            cnt+=l[0]
        elif k==2:
            cnt=(len(l)-1)*(len(l)-2)//2*9*9
            cnt+=(l[0]-1)*(len(l)-1)*9
            cnt+=f(n-10**(len(l)-1)*l[0],1)
        elif k==3:
            cnt=(len(l)-1)*(len(l)-2)*(len(l)-3)//6*9*9*9
            cnt+=(l[0]-1)*(len(l)-1)*(len(l)-2)//2*9*9
            cnt+=f(n-10**(len(l)-1)*l[0],2)
        return cnt
print(f(n,k))