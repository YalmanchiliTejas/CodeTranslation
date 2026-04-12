N, M = map(int, input().split())
A = [list(map(int, input().split())) for i in range(M)]

result = []
stack = []

def path(start, visited):
    if len(visited) >= N:
        result.append(visited[:])
        exit
    stack.append(start)
    if len(stack) > 0:
        nextpoint = stack.pop()
        if nextpoint not in visited:
            visited.append(nextpoint)
            for i in range(M):
                if A[i][0] == start:
                    path(A[i][1], visited)
                if A[i][1] == start:
                    path(A[i][0], visited)
            visited.pop()

path(1, [])
result = list(map(list, set(map(tuple, result))))
print(len(result))
