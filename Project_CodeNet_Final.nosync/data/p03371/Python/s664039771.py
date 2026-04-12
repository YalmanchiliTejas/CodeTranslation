A,B,C,X,Y = map(int,input().split())

ans = A*X+B*Y
for i in range(max(X,Y)+1): #iはABピザの枚数
    a = max(X - i,0)
    b = max(Y - i,0)
    c = 2*i
    sum = A*a + B*b + C*c
    # print(a,b,c,sum)
    if sum < ans:
        ans = sum
print(ans)
