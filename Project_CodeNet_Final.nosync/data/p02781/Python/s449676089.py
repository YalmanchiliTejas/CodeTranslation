N = input()
K = int(input())

k = len(N)
ans = 0

if k < K:
    print(0)
    exit()


def solve(N,K):
    if len(N) < K:
        return 0
    if N[0] == '0':
        return solve(N[1:],K)
    if K == 1:
        return (len(N)-1)*9+int(N[0])
    res = 0
    if K == 2:
        res += (9**2)*(len(N)-1)*(len(N)-2)//2
        res += 9*(len(N)-1)*(int(N[0])-1)
        res += solve(N[1:],K-1)
    if K == 3:
        res += (9**3)*(len(N)-1)*(len(N)-2)*(len(N)-3)//6
        res += (9**2)*(len(N)-1)*(len(N)-2)//2*(int(N[0])-1)
        res += solve(N[1:],K-1)
    return res


print(solve(N,K))