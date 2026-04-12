A, B, C, X, Y = map(int, input().split())
min_num = min(X, Y)
max_num = min(X, Y)
min_price = min(A + B, C * 2)
max_price = min(A + B, C * 2)
answer = min_num * min_price
# print(answer)

if X >= Y:
    answer += (X - min_num) * min(A, C * 2)
else:
    answer += (Y - min_num) * min(B, C * 2)

print(answer)