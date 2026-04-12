import math
A,B,C,X,Y = map(int,input().split())

a = [0,1,2,X-2,X-1,X,abs(X-Y),abs(X-Y+1),abs(X-Y-1)]
b = [0,1,2,Y-2,Y-1,Y,abs(Y-X),abs(Y-X+1),abs(Y-X-1)]
c = [0,1,2,X*2-2,X*2-1,X*2,Y*2-2,Y*2-1,Y*2]
ans = A * X + B * Y
for aa in a:
    for bb in b:
        for cc in c:
            if aa + cc * 0.5 >= X and bb + cc * 0.5 >= Y:
                mny = A * aa + B * bb + C * cc
                if mny < ans:
                    ans = mny
print(ans)