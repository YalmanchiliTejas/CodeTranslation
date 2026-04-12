A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for i in range(min(X,Y)+1):
    nedan = A*(X-i)+B*(Y-i)+2*i*C
    ans = min(ans,nedan)

print(min(ans,C*(max(2*X,2*Y))))