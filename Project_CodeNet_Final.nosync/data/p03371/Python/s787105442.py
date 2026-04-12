A, B, C, X, Y = map(int, input().split())

pay = []

for i in range(max(X,Y)+1):
    pay.append(i*2*C + max(0,X-i)*A + max(0,Y-i)*B)
    
print(min(pay))