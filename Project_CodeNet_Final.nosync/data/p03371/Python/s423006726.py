A, B, C, X, Y = map(int, input().split())
ans = 0
if (A+B)/2 >= C:
    if X >= Y:
        if A/2 <= C:
            ans += C * Y * 2
            ans += A * (X-Y)
        else:
            ans += C * X * 2
    else:
        if B/2 <= C:
            ans += C * X * 2
            ans += B * (Y-X)
        
        else:
            ans += C * Y *2
else:
    ans = A*X + B*Y
    
print(ans)