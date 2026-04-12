def ans(l,k):
    if l==0:
        if k==1:
            return 1
    else:
        if k==1:
            return 0
        elif k<=2**(l+1)-2:
            return ans(l-1,k-1)
        elif k==2**(l+1)-1:
            return ans(l-1,2**(l+1)-3)+1
        elif k<2**(l+2)-3:
            return ans(l-1,2**(l+1)-3)+1 + ans(l-1,k-(2**(l+1)-3)-2)
        else:
            return 2*ans(l-1,2**(l+1)-3)+1
N,X=map(int,input().split())
print(ans(N,X))
