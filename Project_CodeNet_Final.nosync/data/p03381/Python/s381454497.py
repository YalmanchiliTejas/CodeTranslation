'''
def binsearch(x, t):
    low = 0
    high = len(x) - 1
    k = (low + high) // 2
    if x[low] == t:
        return low
    if x[high] == t:
        return high
    while (low <= high):
        if x[k] < t:
            low = k
        elif x[k] > t:
            high = k
        else:
            return k
        k = (low + high) // 2
'''
N=int(input())
X=[int(i) for i in input().split()]
Y=sorted(X)
M=N//2
L=Y[M-1]
R=Y[M]
for i in range(N):
    if X[i]<=L:
        print(R)
    else:
        print(L)

