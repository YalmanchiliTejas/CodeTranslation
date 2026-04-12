n,x = map(int,input().split())
def meet(n,x):
    total = 2**(n+2)-3
    if n == 1:
        bur = 'BPPPB'
        return bur[:x].count('P')
    else:
        if x < total//2+1:
            return meet(n-1,x-1)
        if x == total//2+1:
            return 2**n
        else:
            if x != total:
                return 2**n+meet(n-1,x-total//2-1)
            else:
                return 2**n+meet(n-1,2**(n+1)-3)

print(meet(n,x))
