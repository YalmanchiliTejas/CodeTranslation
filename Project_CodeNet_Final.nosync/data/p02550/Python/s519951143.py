

def solve(N,X,M):
    if X == 0:
        return 0
    memo = [-1]*(M+3)
    acc = [0]*(M+4)
    x = X
    for i in range(M):
        if memo[x] >= 0:
            break
        acc[i+1] = acc[i]+x
        memo[x] = i
        x = (x*x)%M


    end = i
    start = memo[x]
    cycle = end - start

    if N < end:
        return acc[N]

    cycle_sum = acc[end]-acc[start]

    res = acc[start]

    N -= start
    res += (N//cycle)*cycle_sum
    res += acc[start+(N%cycle)]-acc[start]
    return res


N,X,M = map(int,input().split())
print(solve(N,X,M))
