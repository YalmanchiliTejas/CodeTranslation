A,B,C,X,Y = map(int,input().split())

AB_set = C * 2

ans = min(A*X + B*Y, AB_set*max(X,Y), AB_set*min(X,Y) + A*abs(X-min(X,Y)) + B*abs(Y-min(X,Y)))

print(ans)