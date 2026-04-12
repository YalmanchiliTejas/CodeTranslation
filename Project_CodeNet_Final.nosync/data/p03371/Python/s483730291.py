A,B,C,X,Y = map(int,input().split())

ans = min(2*C,A+B) * min(X,Y)

if X > Y:
    ans += min(2*C,A) * (X - Y)
else:
    ans += min(2*C,B) * (Y - X)
    
print(ans)
