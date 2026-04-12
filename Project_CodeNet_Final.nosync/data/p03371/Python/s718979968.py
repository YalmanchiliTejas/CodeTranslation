A,B,AB,AX,BY = map(int,input().split())

a = min(A+B, 2*AB)
if AX <= BY:
    ans = a * AX + (BY - AX) * min(B, 2*AB)
else:
    ans = a * BY + (AX - BY) * min(A, 2*AB)
print(ans)