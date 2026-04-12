N,M = map(int,input().split())
s = [[]for i in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    s[a-1].append(b-1)
    s[b-1].append(a-1)
def func(x,n):
    if n == []:
        return 1
    r = 0
    for i in range(len(n)):
        if n[i] in s[x]:
            hoge = n.copy()
            a = hoge.pop(i)
            r += func(a,hoge)
    return r

print(func(0,list(range(1,N))))