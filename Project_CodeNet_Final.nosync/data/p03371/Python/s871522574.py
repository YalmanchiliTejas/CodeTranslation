A,B,C,X,Y = map(int,input().split())

smaller = X if X < Y else Y
bigger = X if X >= Y else Y
bigger_yen = A if bigger==X else B
cheaper = A if A <B else B
higher = A if A >= B else B

if 2*C >= A + B:
    buy = A*X + B*Y
elif 2*C < A + B:
    if bigger_yen < 2*C:
        buy = smaller*2*C + (bigger-smaller)*bigger_yen
    else:
        buy = bigger*2*C

print(buy)
