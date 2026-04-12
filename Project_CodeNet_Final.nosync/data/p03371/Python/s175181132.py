A,B,C,X,Y = map(int,input().split())
C*=2
minxy = min(X,Y)
maxxy = max(X,Y)
ans1 = C * minxy + A * (X-minxy) + B * (Y-minxy)
ans2 = A*X + B*Y
ans3 = C * maxxy
print (min(ans1,ans2,ans3))