A, B, C, X, Y = map(int, input().split())

AB = A + B

num_A = 0
num_B = 0
num_C = 0
ans_cost = 5000 * 2 * 10**5
if 2 * C > AB:
    num_A = X
    num_B = Y
    num_C = 0
    ans_cost = int(A*num_A + B*num_B + C*num_C)
else:
    min_C = min(X,Y) *2
    max_C = max(X,Y) *2
    for i in range(min_C, max_C+1, 2):
        num_A = X - i / 2
        num_B = Y - i / 2
        if num_A < 1:
            num_A = 0
        if num_B < 1:
            num_B = 0
        
        total_cost = int(A*num_A + B*num_B + C*i)
    
        if total_cost < ans_cost:
            ans_cost = total_cost

print(ans_cost)