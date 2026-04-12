from collections import Counter
N=input()
K=int(input())
km = len(N)
res = 0
if int(N)<=1000:
    for i in range(int(N)):
        c = Counter(str(i+1))
        if len(str(i+1)) - c['0']==K:
            res += 1
    print(res)
    exit()
d = [[0]*3 for _ in range(100001)]
for i in range(100000):
    d[i+1] = d[i][:]
    c = Counter(str(i+1))
    k=len(str(i+1)) - c['0']
    if k<=3:
        d[i+1][k-1] += 1
def rec(n,k):
    re = 0
    if int(n)<100000:
        re = 0
        return d[int(n)][k-1]
    if k==1:
        n = str(int(n))
        return 9*(len(n)-1)+int(n[0])
    t = ''.join(['9']*(len(n)-1))
    t2 = t
    w = (int(n[0])-1)
    if n[0] == '0':
        t2 = n[1:]
        w = 0
    return rec(t2, k) + w*rec(t2, k-1) + rec(str(int(n[1:])), k-1)
print(rec(N,K))
