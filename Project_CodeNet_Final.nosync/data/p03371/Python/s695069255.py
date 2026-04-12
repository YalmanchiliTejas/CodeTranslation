a, b, c, x, y = map(int, input().split())

if x < y:
    big_num = y
    small_num = x
    big_price = b
    #small_price = a
else:
    big_num = x
    small_num = y
    big_price = a
    #small_price = b
    
ans = 0
ans += min(a + b, 2 * c) * small_num
ans += min(big_price, 2 * c) * (big_num - small_num)

print(ans)