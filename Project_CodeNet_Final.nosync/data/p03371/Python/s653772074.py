A,B,C,X,Y = map(int, input().split())

n = min(X,Y)

sum = 0

sum = min(n*2*C, A*n+B*n)

if X>Y:
    n = X-n
    sum = sum + n*A
else:
    n = Y - n
    sum = sum + n*B

sum_ab = X*A + Y*B

sum_a_b = 2*max(X,Y)*C


print(min(sum,sum_ab,sum_a_b))