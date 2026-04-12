a, b, c, x, y = map(int, input().split())
# print(f"{a} {b} {c} {x} {y}")

ax = a * x
by = b * y

# print(f"{ax}")
# print(f"{by}")

cxy = c * (2 * (max(x, y)))
# print(f"{cxy}")

c_maisu_max = 2 * (max(x, y))
# print(f"{c_maisu_max}")

ans = 9999999999
for c_maisu in range(c_maisu_max, -1, -2):
    kingaku = 0
    if c_maisu // 2 >= max(x, y):
        kingaku = c * c_maisu
        # print(kingaku)
    else:
        a_maisu = 0
        b_maisu = 0
        # print(x - (c_maisu // 2))
        # print(y - (c_maisu // 2))
        if x - (c_maisu // 2) > 0:
            a_maisu = x - (c_maisu // 2)
        if y - (c_maisu // 2) > 0:
            b_maisu = y - (c_maisu // 2)
            
        kingaku = (a * a_maisu) + (b * b_maisu) + (c * c_maisu)
        
        # print(kingaku)
        
    ans = min(ans, kingaku)
    
print(ans)