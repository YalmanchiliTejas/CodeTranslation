A,B,C,X,Y = map(int, (input().split()))

if C*2 >= A+B:
    print(A*X+B*Y)
else:
    if X > Y:
        ans=Y*2*C+(X-Y)*A
        ans=min(ans, X*2*C)
    else:
        ans=X*2*C+(Y-X)*B
        ans=min(ans, C*2*Y)
    print(ans)