def subsolve(n, x):
    if(n == 0 and x == 1):
        return 1
    if(x <= 1): # level 1
        return 0
    L1 = (1 << (n + 1)) - 3
    Ps = (1 << n) - 1
    if(x >= 2 * L1 + 2): # level 5
        return 2 * Ps + 1
    if(x > L1 + 2): #level 4
        return Ps + subsolve(n - 1, x - L1 - 2) + 1
    if(x == L1 + 2): # level  3
        return Ps + 1
    return subsolve(n - 1, x - 1) # level 2
if __name__ == '__main__':
    n, x = map(int, input().split())
    print(subsolve(n, x))