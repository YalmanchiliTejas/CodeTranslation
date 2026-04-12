A,B,C,X,Y = map(int, input().split())

min = float('inf')
for k in range(10**5+1):
    temp = 2*C*k+max(X-k,0)*A+max(Y-k,0)*B

    if min > temp:
        min = temp
print(min)