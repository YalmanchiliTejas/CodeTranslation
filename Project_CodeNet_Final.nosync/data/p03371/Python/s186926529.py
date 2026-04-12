[a,b,c,x,y] = [int(x) for x in input().split()]

total_price = a*x+b*y
max_num = max(x,y)

for i in range(0,(max_num+1)*2,2):
    new_x = 0 if x-i//2 <= 0 else x-i//2
    new_y = 0 if y-i//2 <= 0 else y-i//2
    current_price = i*c + new_x*a + new_y*b
    
    if current_price < total_price:
        total_price = current_price

print(total_price)