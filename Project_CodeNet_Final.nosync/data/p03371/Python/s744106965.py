A, B, C, X, Y = map(int, input().split())

ans = 10000000000
for i in range(2 * max(X, Y) + 1):
    A_half = i
    B_half = i
    cur_cost = i * C
    
    left_A_half = 2 * X - A_half
    left_B_half = 2 * Y - B_half
    if left_A_half > 0 :
        if left_A_half % 2 == 0:
            cur_cost += left_A_half // 2 * A
        else:
            cur_cost += (left_A_half // 2 + 1) * A
    
    if left_B_half >= 0:
        if left_B_half % 2 == 0:
            cur_cost += left_B_half // 2 * B
        else:
            cur_cost += (left_B_half // 2 + 1) * B
    
    ans = min(ans, cur_cost)
    
print(ans)