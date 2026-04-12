class findroop:
    def __init__(self, n, nex):
        self.n = n
        self.next = nex

    #遷移start回でループに入る、end回でループする
    #A->B->C->D->B: return=(1, 4)
    #C->D->B->C   : return=(0, 3)
    #O(n)
    def findroop(self, start):
        roopstart = -1
        roopend = -1
        visited = [False for i in range(self.n)]
        visitlist = []
        now = start
        for i in range(self.n):
            if visited[now]:
                roopend = i
                break
            else:
                visited[now] = True
                visitlist.append(now)
                now = self.next(now)
        
        for i in range(len(visitlist)):
            if visitlist[i] == now:
                roopstart = i

        return (roopstart, roopend)


N,X,M = list(map(int, input().split()))

fr = findroop(M, lambda x: x**2 % M)

roopstart, roopend = fr.findroop(X)

ans = 0
if N <= roopstart:
    for i in range(N):
        ans += X
        X = (X**2)%M
else:
    for i in range(roopstart):
        ans += X
        X = (X**2)%M

    N -= roopstart
    roopsum = 0
    for i in range(roopend-roopstart):
        roopsum += X
        X = (X**2) % M
    ans += (N // (roopend-roopstart)) * roopsum

    N = N % (roopend-roopstart)

    for i in range(N):
        ans += X
        X = (X**2) % M

print(ans)