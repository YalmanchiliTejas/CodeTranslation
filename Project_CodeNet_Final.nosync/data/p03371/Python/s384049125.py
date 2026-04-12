A,B,C,X,Y = map(int,input().split())
min_price = float("inf")
c_count = 0
while True:
    min_price = min(min_price,(A * X) + (B * Y) + (C * c_count))
    if X == 0 and Y == 0:
        break
    X = 0 if X <= 0 else (X-1)
    Y = 0 if Y <= 0 else (Y-1)
    c_count += 2
print(min_price)