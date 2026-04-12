A, B, ABhalf, X, Y = map(int, input().split())
ans_1 = max(X, Y) * 2 * ABhalf
ans_2 = 2 * Y * ABhalf + abs(X - Y) * A
ans_3 = 2*X*ABhalf+abs(X-Y)*B
ans_4 = X * A + Y * B
ans = min(ans_1, ans_2, ans_3, ans_4)
print(ans)
