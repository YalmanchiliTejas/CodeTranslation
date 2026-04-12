A,B,C,X,Y = map(int, input().split())
ans = float('inf')
for i in range(0,200001,2):
    a = max(0,X-i//2)
    b = max(0,Y-i//2)
    s = a*A+b*B+i*C
    ans = min(ans, s)
print(ans)