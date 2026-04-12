A,B,C,X,Y = list(map(int,input().split()))

tan = A*X + B*Y
hukuA = max(X,Y)*2*C
hukuB = min(X,Y)*2*C + (max(X,Y)-min(X,Y)) * (A if X>=Y else B)

print(min(tan,hukuA,hukuB))