A,B,C,X,Y = map(int,input().split())
if 2*C >= A + B:
    ans = A*X+B*Y
else:
    n_c = 2*min(X,Y)
    #print(n_c)
    if X > Y:
        ans = min(n_c*C+A*(X-n_c/2),C*2*X)
    else:
        ans = min(n_c*C+B*(Y-n_c/2),C*2*Y)
print(int(ans))
