A,B,C,X,Y=map(int,input().split())

ANS=10**12
for i in range(0,max(X,Y)*2+1,2):
    XRE=max(X-i//2,0)
    YRE=max(0,Y-i//2)

    if ANS>i*C+XRE*A+YRE*B:
        ANS=i*C+XRE*A+YRE*B

    #print(i,i*C+XRE*A+YRE*B)

print(ANS)