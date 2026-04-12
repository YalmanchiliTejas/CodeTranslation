N, X = map(int,input().split())
a = [1]
p = [1]
def solve():
    for i in range(N):
        a.append(a[i] * 2 + 3)
        p.append(p[i] * 2 + 1)

    print(getAns(N,X))

def getAns(L,x):
    if L == 0:
        if x <= 0:
            return 0
        else:
            return 1
    elif x <= 1 + a[L-1]:
        return getAns(L-1, x-1)
    else:
        return p[L-1] + 1 + getAns(L-1, x-2-a[L-1])

if __name__ == '__main__':
    solve()