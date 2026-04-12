a, b, c, x , y = map(int, input().split())
ans = []
# そのまま
ans.append(a*x + b*y)
# 全部1/2
ans.append(max(x, y)*c*2)
# 1/2 あまりをそのまま
p = a if x > y else b
ans.append(min(x, y)*c*2 + (abs(x - y) * p))
print(min(ans))