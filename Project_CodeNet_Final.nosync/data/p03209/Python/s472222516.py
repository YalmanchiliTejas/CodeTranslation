"""
22.40.00

"""

N,X = map(int, input().split())
# 層の数 : 2**(N+2) - 3
# パティの数 : 2**(N+1) - 1
# 肉の数 : 2**(N+1) - 2
l = N
cnt = 0
while l >= 0:
    n_all = 2**(l+2) - 3
    p_all = 2**(l+1) - 1
    if l == 0:
        cnt += 1
    if X == 1:
        break
    elif X == n_all:
        cnt += p_all
        break
    elif X == (n_all+1)//2:
        cnt += (p_all+1) // 2
        break
    elif 1 < X < (n_all+1)//2:
        X -= 1
    elif (n_all+1)//2 < X < n_all:
        X -= (n_all+1)//2
        cnt += 2**l
    l -= 1

print(cnt)

