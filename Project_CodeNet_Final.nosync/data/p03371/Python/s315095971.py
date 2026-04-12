a, b, c, x, y = map(int, input().split())
print(min([a*max(x-i, 0)+b*max(y-i, 0)+c*2*i for i in range(max(x, y)+1)]))
