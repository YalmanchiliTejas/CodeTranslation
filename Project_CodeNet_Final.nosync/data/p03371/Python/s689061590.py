A,B,C,X,Y = map(int,input().split())
minS = float('inf')
for i in range(0,2*max(X,Y)+2,2):
    minS = min(minS,C*i + B*max(0,Y-i/2) + A*max(0,X-i/2))

print(int(minS))