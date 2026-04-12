def L(N):
    if N==0:
        return 1
    else:
        prev_L = L(N-1)
        return 1+prev_L+1+prev_L+1
def numP(N):
    if N==0:
        return 1
    else:
        prev_P = numP(N-1)
        return 2*prev_P+1
def eated_P(N,X):
    ans = 0
    fh=int(L(N)/2)
    if X<=0:
        return 0
    elif N==0:
        return 1
    elif fh<X:
        ans = numP(N-1)+1+eated_P(N-1,X-fh-1)
        return ans
    else:
        rem = X-1
        ans = eated_P(N-1,rem)
        return ans
N,X = map(int,input().split())
print(eated_P(N,X))