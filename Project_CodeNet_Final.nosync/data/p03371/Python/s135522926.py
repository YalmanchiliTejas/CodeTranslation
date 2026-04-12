A,B,H,x,y = map(int,input().split(" "))
money = 0
if A + B <= H * 2:
    money += A * x
    money += B * y
else:
    if x >= y:
        money += (y * H) * 2
        if A <= H * 2:
            money += (x - y) * A
        else:
            money += (x - y) * (H * 2)
    else:
        money += (x * H) * 2
        if B <= H * 2:
            money += (y - x) * B
        else:
            money += (y - x) * (H * 2)
print(money) 