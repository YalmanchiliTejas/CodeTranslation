x=input().split()
x=[int(x[i]) for i in range(len(x))]
if x[0]+x[1]<=2*x[2]:
    print(x[0]*x[3]+x[1]*x[4])
else:
    if x[3]>x[4]:
        ans=x[4]*2*x[2]+(x[3]-x[4])*x[0]
        ans=min(ans,x[3]*2*x[2])
    else:
        ans=x[3]*2*x[2]+(x[4]-x[3])*x[1]
        ans=min(ans,x[4]*2*x[2])
    print(ans)