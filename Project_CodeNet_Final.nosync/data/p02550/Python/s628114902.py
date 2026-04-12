N, X, M = map(int, input().split())

flag = [False]*(10**5 + 10)
A = [X]
for i in range(N):
    X = X**2 % M
    if flag[X]:
        break
    
    flag[X] = True
    A.append(X)

# return index when a appears for the first time
index = A.index(X)

# A's before loop begins
loop_bef = A[0:index]

# A's where loop exists
loop = A[index:]

# number of loops
num_loop = (N - len(loop_bef)) // len(loop)
num_aft_loop = (N - len(loop_bef)) % len(loop)

ans = sum(loop_bef) + sum(loop)*num_loop + sum(loop[:num_aft_loop])

print(ans)