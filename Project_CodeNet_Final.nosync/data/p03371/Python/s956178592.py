A, B, C, X, Y = map(int, input().split())
C *= 2

ans1 = A*X + B*Y
ans2 = C*max(X,Y)

ans3 = C*min(X,Y)
if X < Y:
    ans3 += (Y-X)*B
else:
    ans3 += (X-Y)*A

#print(ans1, ans2, ans3)
print(min(ans1, ans2, ans3))