r,g,b = map(int,input().split())
1 <= r <= 9
1 <= g <= 9
1 <= b <= 9
number1 = r*100 + g*10 + b
if number1%4 == 0:
    print("YES")
else:
    print("NO")