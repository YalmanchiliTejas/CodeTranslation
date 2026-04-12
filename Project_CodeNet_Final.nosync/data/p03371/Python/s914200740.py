a, b, c, x, y = map(int, input().split())
if a+b >2*c:
    mini = min(x,y) #ABセットで揃えられる枚数
    ab_cost = mini * 2 * c
    remain = max(x-mini, y-mini)
    if x > y:
        remain_cost = min(remain * a, remain*2*c)
    else:
        remain_cost = min(remain * b, remain*2*c)
    print(ab_cost + remain_cost)
else:
    print(a*x+b*y)