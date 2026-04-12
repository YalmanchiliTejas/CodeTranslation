A, B, C, X, Y = map(int, input().split())

min_amt = 2*10**5*5001

for i in range(0, max(X, Y) * 2 + 1) :
    min_amt = min(min_amt, C*2*i + max(0, (X - i) * A) + max(0, (Y - i) * B))
    
print(min_amt)