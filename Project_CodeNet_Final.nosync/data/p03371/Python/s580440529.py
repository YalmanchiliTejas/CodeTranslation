A, B, C, X, Y = map(int, input().split())
sum = 0
min_num = 10**10
num = [0]*3
for c in range(max(X, Y)+1):
    sum += C*c*2
    num[0] = c*2
    sum += A*max(0,X-c) + B*max(0, Y-c)
    num[1] = max(0, X-c)
    num[2] = max(0, Y-c)
    if min_num > sum:
        min_num = sum
    sum = 0
print(min_num)