A,B,C,X,Y=map(int, input().split())

res = float('inf')
for i in range(max(2*X,2*Y)+1):
    tmp = 2*i*C + max(0,X-i)*A + max(0,Y-i)*B
    res = min(res, tmp)
print(res)
