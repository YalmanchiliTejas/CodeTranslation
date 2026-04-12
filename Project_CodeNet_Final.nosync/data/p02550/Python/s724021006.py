N,X,M = map(int,input().split())

is_appear = [-1]*M
a = []
_len = 0
while is_appear[X] == -1:
    a.append(X)
    is_appear[X] = _len
    _len += 1
    X = X*X % M

loop_len = _len-is_appear[X]
loop_total = 0
for i in range(is_appear[X], _len):
    loop_total += a[i]

ans = 0
if N <= _len:
    for i in range(N):
        ans += a[i]
    
    print(ans)
else:
    for i in range(is_appear[X]):
        ans += a[i]
        N -= 1
    
    ans += loop_total * (N // loop_len)
    
    for i in range(N%loop_len):
        ans += a[is_appear[X]+i]
    
    print(ans)
