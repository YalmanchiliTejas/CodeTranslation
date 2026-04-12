A, B, C, X, Y=map(int, input().split())
m=max(X, Y)
print(min([C*2*i+A*max(0, X-i)+B*max(0, Y-i) for i in range(m+1)]))