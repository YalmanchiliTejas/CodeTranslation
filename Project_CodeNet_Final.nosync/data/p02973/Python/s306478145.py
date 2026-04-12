import bisect
N = int(input())
A = [0 for i in range(N)]
for i in range(N):
    A[i] = int(input())
now = [-A[0]]
 
for i in range(1, N):
 
    index = bisect.bisect_right(now, -A[i])
    if index == len(now):
        now.append(-A[i])
    else:
        now[index] = -A[i]
print(len(now))