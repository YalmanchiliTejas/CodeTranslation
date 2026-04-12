a,b,c,x,y = map(int, input().split())

sum1 = a*x + b*y

num = min(x, y)
sum2 = num * 2 * c + a*(x-num) + b*(y-num)
sum3 = max(x,y) * 2 * c

print(min(sum1, sum2, sum3))