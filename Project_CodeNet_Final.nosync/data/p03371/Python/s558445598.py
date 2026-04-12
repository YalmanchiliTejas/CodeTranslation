A,B,AB,X,Y = map(int,input().split())

ans = min(X,Y)*min(2*AB, A+B)
cnt_A = min(X,Y)
cnt_B = min(X,Y)

#残り
if X > cnt_A:#Aが足りないときa
    ans += min(2*AB,A)*(X-cnt_A)
else:#Bが足りないとき
    ans += min(2*AB,B)*(Y-cnt_B)
    
print(ans)