import sys
if __name__ == "__main__":
    A, B, C, X, Y = list(map(int, (input().split(' '))))
    cost_A = A * X
    cost_B = B * Y
    least_cost = cost_A + cost_B
    max_cnt = 0
    if X >= Y:
        max_cnt = X
    else:
        max_cnt = Y
    for i in range(0, 2*max_cnt+1, 2):
#        print(i)
        buf_cost_A = 0
        buf_cost_B = 0
        buf_cost = C * i
        if (X - i*0.5) > 0:
            buf_cost_A = (X - i*0.5) * A
        if (Y - i*0.5) > 0:
            buf_cost_B = (Y - i*0.5) * B
#        print(buf_cost+buf_cost_A+buf_cost_B)
        if least_cost > (buf_cost + buf_cost_A + buf_cost_B):
            least_cost = buf_cost + buf_cost_A + buf_cost_B
    print(int(least_cost))