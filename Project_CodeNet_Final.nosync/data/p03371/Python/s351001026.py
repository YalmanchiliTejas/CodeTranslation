A, B, C, X, Y = map(int, input().split())

answer_1 = A * X + B * Y # すべてA、Bで買う場合
answer_2 = C * 2 * max(X, Y) # すべてCで買う場合

# answer_3: 先にA,Bを買ってからあまりをCで補う場合
# answer_4: 先にCを買ってから最後に残りA,Bで補う場合
if X > Y:
    answer_3 = A * Y + B * Y + C * (X - Y) * 2
    answer_4 = A * (X - Y) + C * Y * 2
else:
    answer_3 = A * X + B * X + C * (Y - X) * 2
    answer_4 = B * (Y - X) + C * X * 2

answer = min(answer_1, answer_2, answer_3, answer_4)
print(answer)