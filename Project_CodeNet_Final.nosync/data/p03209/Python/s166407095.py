n,x=map(int,input().split())

B=[[1,1]]
for i in range(1,n+1):
    B.append([B[i-1][0]*2+3,B[i-1][1]*2+1])

#print(B)

def bur(a,b):
    if a==0 :
        if b==0 :
            return 0
        else :
            return 1
    elif b<=1 :
        return 0
    elif b<=1+B[a-1][0] :
        return bur(a-1,b-1)
    elif b<=1+B[a-1][0]+1 :
        return B[a-1][1]+1
    elif b<=1+B[a-1][0]+1+B[a-1][0] :
        return B[a-1][1]+1+bur(a-1,b-2-B[a-1][0])
    elif b<=1+B[a-1][0]+1+B[a-1][0]+1 :
        return B[a-1][1]*2+1
    print(a)
    

print(bur(n,x))
