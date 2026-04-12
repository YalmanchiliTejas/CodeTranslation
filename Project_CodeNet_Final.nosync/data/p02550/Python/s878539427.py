N, X, M = map(int,input().split())

def cal(x):
    return pow(x,2,M)

memo = set()
lis = []
while X not in memo:
    memo.add(X)
    lis.append(X)
    X = cal(X)
pos = lis.index(X)

if pos >= N:
    print(sum(lis[:N]))
else:
    print(sum(lis[:pos]) + ((N-pos)//(len(memo)-pos)) * sum(lis[pos:]) + sum(lis[pos:(N-pos)%(len(memo)-pos)+pos]))