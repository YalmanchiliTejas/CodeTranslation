import bisect
N = int(input())
A = [int(input()) for _ in range(N)]
List = [-A[0]]
for i in range(1, N):
    if -List[-1]>=A[i]:
        List.append(-A[i])
    else:
        index = bisect.bisect_right(List, -A[i])
        List[index] = -A[i]
print(len(List))
        