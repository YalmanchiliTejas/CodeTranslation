a,b,c,x,y = map(int, input().split())
if c*2 < (a+b):
    result_1 = c*(min(x,y))*2
    if x == y:
        print(result_1)
    elif x > y:
        result_2 = x-y
        result = result_1 + (result_2)*a
        print(result)
    elif x < y:
        result_2 = y-x
        if (result_2)*b <= result_2*2*c:
            result = result_1 + (result_2)*b
            print(result)
        else:
            result = result_1 + (result_2*2*c)
            print(result)
else:
    print(a*x+b*y)