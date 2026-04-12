i = input()
A,B,C,X,Y = i.split()
A = int(A)
B = int(B)
C = int(C)
X = int(X)
Y = int(Y)

if (A + B) <= (C*2):
    print(A*X + B*Y)
elif X < Y:
    if C*2< B:
        print(C*Y*2)
    else:
        print(C*X*2 + B*(Y-X))
else:
    if C*2< A:
        print(C*X*2)
    else:
        print(C*Y*2 + A*(X-Y))
