A,B,C,X,Y = map(int,input().split())

MA, MI = max(X,Y), min(X,Y)
ans = 2 * C * MA

if X != Y:
    for i in range(MA-MI):
        if X > Y:
            tmp = ans - 2*C + A
        else:
            tmp = ans - 2*C + B
        ans = min(ans,tmp)
        
for j in range(MI):
    tmp = ans - 2*C + A + B
    ans = min(ans,tmp)

print(ans)
