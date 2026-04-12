# C - Half and Half

A, B, C, X, Y = map(int, input().split())

# 条件を満たすときのA, B, ABの買い方を全列挙したい
# A, Bの枚数は、ABの値が決まれば、一意に定まるため、
# ABのみループする。

ans = 10**18
for i in range(0, max(X, Y)*2+1, 2):
    x = max(X-i//2, 0)
    y = max(Y-i//2, 0)
    ans = min(ans, x*A + y*B + i*C)
    
print(ans)