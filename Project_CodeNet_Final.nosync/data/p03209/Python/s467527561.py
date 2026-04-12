N,X = map(int,input().split())

burger_len = [1]*(N+1)
burger_putty = [1]*(N+1)
for i in range(1,N+1):
    burger_len[i] = 3 + 2*burger_len[i-1]
    burger_putty[i] = 1 + 2*burger_putty[i-1]

def get_x(n,x):
    if n == 0:
        return int(x>0)
    tmp_len = burger_len[n-1]
    if x <= (tmp_len +1):
        return get_x(n-1,x-1)
    elif x == tmp_len + 2:
        return 1 + burger_putty[n-1]
    else:
        return burger_putty[n-1] + 1 + get_x(n-1,x-tmp_len-2)

print(get_x(N,X))