N,X=map(int,input().split())
Z=[0]+[ 2**(i+2) -3 for i in range(N+1)]
B=[0]+[ 2**(i+1) -2 for i in range(N+1)]
P=[0]+[ 2**(i+1) -1 for i in range(N+1)]
ans=0
def arg(l,i):
    global ans
    if l != 0 :
        if Z[l]/2+1/2 < i :
            ans += (1 + P[l-1])
#            print("uga")
            return  arg( l-1 , i-( (Z[l]-1)/2 + 1 ) ) 

        elif Z[l]/2 +1/2  > i :
 #           print("aho")
            return arg( l-1 , i - 1)

        else :
            ans += P[l-1] + 1
        #    print("hoge")
    else :
        pass
arg(N+1,X)
print(ans)
