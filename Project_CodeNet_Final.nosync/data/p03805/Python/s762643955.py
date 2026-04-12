#input
n, m = map(int, input().split())
A = []
B = []
for i in range(m):
    a, b = map(int,input().split())
    A.append(a)
    B.append(b)

#operation
pointvisited = [False] * (n + 1)
pointvisited[0] = True
pointvisited[1] = True
ans = 0
def DFS(point):
    if all(pointvisited):
        global ans
        ans += 1
    nextpoints = findnextpoint(point)
    for nextpoint in nextpoints:
        if not pointvisited[nextpoint]:
            pointvisited[nextpoint] = True
            DFS(nextpoint)
            pointvisited[nextpoint] = False

def findnextpoint(point):
    nepo = []
    for i, a in enumerate(A):
        if a == point:
            nepo.append(B[i])
    for i, b in enumerate(B):
        if b == point:
            nepo.append(A[i])
    return nepo

#output
DFS(1)
print(ans)