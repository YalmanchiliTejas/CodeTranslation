n, x = map(int, input().split())

patty = [0]*(n+1)
length = [0]*(n+1)
for L in range(n+1):
    if L==0:
        patty[L] = 1
        length[L] = 1
    else:
        patty[L] = patty[L-1]*2+1
        length[L] = length[L-1]*2+3

def patty_n(L,X): # length[L]>=X>=0
    # print('L,X',L,X)
    if X==0:
        return 0
    elif L==0:
        return 1
    else:
        l = length[L-1]
        if X==1:
            return 0
        elif 1<X<=1+l:
            return patty_n(L-1, X-1)
        else:
            return patty[L-1]+1+patty_n(L-1, X-l-2)

print(patty_n(n,x))