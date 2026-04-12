A , B , C , X , Y = map(int,input().split())
# 場合分けして考える
# 全てABピザ、
# 可能な限りAB、余りをA or B
# 全てA or B
# 上記の３パターンのうち、最も小さな金額が回答？
AB = max(X, Y) * 2 * C
ABandAorB = min(X,Y)* 2 * C + ( ((X-Y)* A  ) if  X > Y else ((Y -X) *B))
AorB = X * A + Y * B
print(min(AB,ABandAorB ,AorB ))