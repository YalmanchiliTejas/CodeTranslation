A,B,C,X,Y = map(int,input().split())

if A+B>=2*C:
    if X>Y:
        if A>=2*C:
            ans = Y*2*C + (X-Y)*2*C
        else:
            ans = Y*2*C + (X-Y)*A
    else:
        if B>=2*C:
            ans = X*2*C + (Y-X)*2*C
        else:
            ans = X*2*C + (Y-X)*B
else:
    ans = X*A + Y*B

print(ans)