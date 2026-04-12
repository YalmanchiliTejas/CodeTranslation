#ABC095C
A, B, C, X, Y=map(int, input().split())
ans1=X*A+Y*B
if X>Y:
    ans2=Y*2*C+(X-Y)*A
else:
    ans2=X*2*C+(Y-X)*B
ans3=max(X, Y)*2*C
print(min(ans1, ans2, ans3))
