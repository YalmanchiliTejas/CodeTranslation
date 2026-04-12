sum = 0
A,B,C,X,Y = map(int,input().split())
AB = A+B
sum += min(C*2*(min(X,Y)),AB*(min(X,Y)))
Z = max(X-Y,Y-X)
if X-Y>0:
    sum += min(A*(X-Y),C*2*(X-Y))
else:
    sum += min(B*(Y-X),C*2*(Y-X))

print(sum)
