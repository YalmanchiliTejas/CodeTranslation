a,b,c,x,y = map(int,input().split())
max_pay = x * a + y * b
i = 0
while (x - i)>=0 or (y - i)>=0:
    pay = max((x - i),0) * a + max((y - i),0) * b + c * i * 2
    #print(pay)
    max_pay = min(max_pay,pay)
    i += 1
print(max_pay)