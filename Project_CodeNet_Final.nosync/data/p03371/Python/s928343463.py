A,B,C,X,Y=map(int,input().split())
total=0
if A+B<=C*2:
    print(A*X+B*Y)
    exit(0)
else:
    total+=min(X,Y)*2*C

if X<Y:
    if B<2*C:
        total+=(Y-X)*B
    else:
        total+=(Y-X)*C*2

if X>Y:
    if A<2*C:
        total+=(X-Y)*A
    else:
        total+=(X-Y)*C*2

print(total)
