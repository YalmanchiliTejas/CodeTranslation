A, B, C, X, Y = map(int, input().split())
ans = 0

if A + B <= 2*C:
    ans = A*X + B *Y
    
else:
    ans += C*2*min(X, Y)
    nokori = max(X, Y)-min(X, Y)
    
    if X > Y:
        if A >= 2*C:
            ans += 2*C*nokori
        else:
            ans += A*nokori
    
    elif X < Y:
        if B >= 2*C:
            ans += 2*C*nokori
        else:
            ans += B*nokori

print(ans)