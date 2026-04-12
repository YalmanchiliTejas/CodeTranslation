N, X = map(int, input().split())


def dfs(n, x):
    if n == 0:
        return 1
    elif x == 1:
        return 0
    elif 1 < x and x <= 1+na[n-1]:
        return dfs(n-1, x-1)
    elif 2+na[n-1] == x:
        return np[n-1]+1
    elif 2+na[n-1] < x and x <= 2+2*na[n-1]:
        return np[n-1]+1+dfs(n-1, x-2-na[n-1])
    elif x == 3+2*na[n-1]:
        return 2*np[n-1]+1

na = [1]
np = [1]
for i in range(N):
    na.append(na[-1]*2+3)
    np.append(np[-1]*2+1)
print(dfs(N, X))
