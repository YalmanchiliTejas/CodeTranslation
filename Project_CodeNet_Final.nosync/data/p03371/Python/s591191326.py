A,B,C,X,Y = map(int,input().split())
ans = list()
big = max(X,Y)

for i in range(big+1):
    x = X - i if X - i >= 0 else 0
    y = Y - i if Y - i >= 0 else 0 
    goukei = (A*x)+(B*y)+(C*i*2) 
    ans.append(goukei)
print(min(ans))