a,b,c,x,y = [int(i) for i in input().split(" ")]

# if a+b > c:
max_num = max(x,y)
cost_1 = max_num*2*c
# print(cost_1)
min_num = min(x,y)
cost_2 = (x-min_num)*a + (y-min_num)*b + c*2*min_num

cost_3 = (x*a + y*b)
# print(cost_2)
print(min(cost_3,min(cost_1,cost_2)))
# else:
#     print(a*x + b*y)