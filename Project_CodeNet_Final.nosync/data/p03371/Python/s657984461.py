A,B,C,X,Y = map(int,input().split())
min_ = min(X,Y)
max_ = max(X,Y)

res = A*X + B*Y

m = 2 * C * max(X, Y);

sum = C * 2* min_

if(C<=0.5 * A and C <= 0.5 * B):
    sum += 2*C*(max_-min_)

elif(max_==X):
    sum += (max_-min_)*A
else:
    sum += (max_-min_)*B
    
print(min(m,min(res,sum)))