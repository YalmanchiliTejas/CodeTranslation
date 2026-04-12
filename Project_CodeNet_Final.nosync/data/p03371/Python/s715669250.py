A, B, C, X, Y = map(int, input().split())

cost = 10**9
for i in range(2*10**5+1):
    if i%2==0:
        a_num = X-int(0.5*i)
        b_num = Y-int(0.5*i)
        if a_num < 0 and b_num < 0:
            break
        cost = min(cost, A*max(a_num, 0)+B*max(b_num, 0)+C*i)

print(cost)