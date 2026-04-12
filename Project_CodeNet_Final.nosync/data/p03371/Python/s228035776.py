A,B,C,X,Y = map(int,input().split())
a,b,c = 0,0,0
ans = 0
for c in range (0,2*max(X,Y)+1,2):
    a = max(0,X - c//2)
    b = max(0,Y - c//2)
    if(c==0):
        ans = A*a + B*b + C*c
    else:
        if(ans > A*a + B*b + C*c):
            ans = A*a + B*b + C*c
print(ans)
