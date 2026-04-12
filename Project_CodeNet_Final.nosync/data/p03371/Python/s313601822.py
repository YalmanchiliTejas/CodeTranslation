A,B,C,X,Y = list(map(int, input().split()))
p = 0
while max(X,Y) > 0:
    if ((min(X, Y) >= 1) & (A+B > C*2)) | ((X >= 1) & (A > C*2)) | ((Y >= 1) & (B > C*2)):
        p += C * 2
        X -= 1
        Y -= 1
    elif (X >= 1) & (A < C*2):
        p += A*1
        X -= 1
    elif (Y >= 1) & (B < C*2):
        p += B*1
        Y -= 1
print(p)