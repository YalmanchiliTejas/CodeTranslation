a = list(map(int,input().split()))
A = a[0]
B = a[1]
C = a[2]
X = a[3]
Y = a[4]
if A + B <= 2*C:
    print(str(A*X + B*Y))
else:
    if X <= Y:
        #2X枚のABピザを作る。残りY-X枚のBピザが必要
        if B <= 2*C:
            print(str(2*X*C + (Y-X)*B))
        else:
            print(str(2*Y*C))
    else:
        if A <= 2*C:
            print(str(2*Y*C + (X-Y)*A))
        else:
            print(str(2*X*C))