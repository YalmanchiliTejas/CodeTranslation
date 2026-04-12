import sys
n, x = map(int, input().split())
ans = 0
layer = [1 for _ in range(n+1)]
patty = [1 for _ in range(n+1)]
for i in range(1,n+1):
    layer[i] = 2*layer[i-1]+3
    patty[i] = 2*patty[i-1]+1
def eat(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    elif x <= 1+layer[n-1]:
        return eat(n-1, x-1)
    elif x == 2+layer[n-1]:
        return patty[n-1]+1
    elif x <= 2+2*layer[n-1]:
        return patty[n-1]+1+eat(n-1, x-2-layer[n-1])
    else:
        return 2*patty[n-1]+1
ans = eat(n, x)
print(ans)
