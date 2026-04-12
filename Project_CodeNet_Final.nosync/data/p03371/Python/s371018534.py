A, B, C, X, Y = map(int, input().split())
ans_list = []
for i in range(1000001):
    ans_list.append(2*i*C + max(0, X-i)*A + max(0, Y-i)*B)
print(min(ans_list))