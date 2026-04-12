N = input()
K = int(input())

memo = [[[0 for _ in range(4)] for _ in range(2)] for _ in range(len(N))]

N_size = len(N)

def dfs(i=0,small=0,k = K):
    if k == 0: return 1
    if i > N_size - 1: return 0
    if memo[i][small][k] > 0: return memo[i][small][k]

    ret = 0
    dgt = int(N[i])

    if small == 1:
        ret += dfs(i+1,1,k-1) * 9
        ret += dfs(i+1,1,k)
    else:
        if dgt == 0:
            ret += dfs(i+1,0,k)
        else:
            ret += dfs(i+1,1,k)
            ret += dfs(i+1,1,k-1) * (dgt-1)
            ret += dfs(i+1,0,k-1)

    memo[i][small][k] = ret
    return ret

print(dfs())
