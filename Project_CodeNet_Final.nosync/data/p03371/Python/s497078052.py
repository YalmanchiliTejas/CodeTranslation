a, b, ab, x, y = (int(i) for i in input().split())  
if a + b <= (ab * 2):
    print(a*x+b*y)
else:
    num_ab = min(x,y)*2
    price = 0
    price += num_ab*ab + (x-num_ab/2)*a + (y-num_ab/2)*b
    price2 = 0
    price2 += max(x,y)*ab*2
    print(int(min(price,price2)//1))