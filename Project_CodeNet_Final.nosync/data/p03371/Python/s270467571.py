A, B, AB, X, Y = map(int,input().split())
min_sheet = min(X,Y)

if A + B >= AB * 2:
    min_price = min(AB * 2 * min_sheet + A * (X - min_sheet) + B * (Y - min_sheet), AB * 2 * max(X,Y))
else:
    min_price = A * X + B * Y
    
print(min_price)