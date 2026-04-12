n, x = map(int, input().split())

bc = [0] * 51
pc = [0] * 51
l = [0] * 51
pc[0] = 1
l[0] = 1
for i in range(1, 51):
    bc[i] = bc[i-1] * 2 + 2
    pc[i] = pc[i-1] * 2 + 1
    l[i] = bc[i] + pc[i]

def ans(nn, xx):
    if nn == 0:
        return 1
    if xx == 1:
        return 0
    elif xx < (l[nn] + 1) //2:
        return ans(nn-1, xx-1)
    elif xx == (l[nn] + 1) //2:
        return pc[nn-1] + 1
    else:
        return pc[nn-1] + 1 + ans(nn-1, xx-((l[nn]+1)//2) )

print(ans(n, x))