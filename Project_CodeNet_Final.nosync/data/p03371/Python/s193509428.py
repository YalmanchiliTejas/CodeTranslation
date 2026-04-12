A,B,C,X,Y=map(int,input().split())
ans=A*X+B*Y
if X>Y:
    if A+B>2*C:
        ans-=(A+B-2*C)*Y

    if A>2*C:
        ans-=(A-2*C)*(X-Y)
elif X<Y:
    if A+B>2*C:
        ans-=(A+B-2*C)*X
    if B>2*C:
        ans-=(B-2*C)*(Y-X)
elif X==Y:
    if A+B>2*C:
        ans-=(A+B-2*C)*X

print(ans)