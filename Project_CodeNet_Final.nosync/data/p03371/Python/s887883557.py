x = 0
y = 0
A,B,C,X,Y = map(int,input().split())
if X > Y :
    x = 1
else :
    y = 1
answer = min(X,Y)*min(A+B,C*2) + (max(X,Y)-min(X,Y))*(x*min(A,C*2)+y*min(B,C*2))
print(answer)

