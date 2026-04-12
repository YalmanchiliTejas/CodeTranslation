N = int(input())
A = list(map(int,input().split()))

ALL = sum(A)
res = 0

for a in A: 
    ALL -= a    
    res = (res + ALL *a) % (10**9+7)

print(res)