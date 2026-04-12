line = list(map(int,input().split(" ")))
A,B,C,X,Y = line[0],line[1],line[2],line[3],line[4]

payment = 0
min_AB = min(X,Y)
if(A+B< 2 * C):
    payment += (A+B) * min_AB
else:
    payment += 2 * C * min_AB

if(X == max(X,Y)):
    if(A > 2 * C ):
        payment += 2*C*(max(X,Y)-min(X,Y))
    else:
        payment += A*(max(X,Y)-min(X,Y))
else:
    if(B > 2*C):
        payment += 2*C*(max(X,Y)-min(X,Y))
    else:
        payment += B*(max(X,Y)-min(X,Y))
print(payment)
