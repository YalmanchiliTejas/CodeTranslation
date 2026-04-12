A, B, C, X, Y = map(int, raw_input().split())

if A+B<2*C:
    sum=A*X+B*Y
else:
    sum=2*C*min(X,Y) + A*(X-(min(X,Y))) + B*(Y-(min(X,Y)))
    if sum > C*max(X,Y)*2:
        sum=C*max(X,Y)*2

print sum