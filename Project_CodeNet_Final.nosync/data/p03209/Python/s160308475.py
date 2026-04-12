from sys import stdin
N, X = [int(x) for x in stdin.readline().rstrip().split()]

heights = [1]
putties = [1]
for _ in range(N):
    heights.append(heights[-1] * 2 + 3)
    putties.append(putties[-1] * 2 + 1)


def solve(n, x):
    if n == 0 and x == 1:
        return 1
    elif x == 1:
        return 0
    elif 1 < x <= 1+heights[n-1]:
        return solve(n-1, x-1)
    elif x == 2+heights[n-1]:
        return 1+putties[n-1]
    elif 2+heights[n-1] < x <= 2+2*heights[n-1]:
        return putties[n-1]+1+solve(n-1,x-2-heights[n-1]) 
    elif x == 3+2*heights[n-1]:
        return 2*putties[n-1]+1
print(solve(N, X))