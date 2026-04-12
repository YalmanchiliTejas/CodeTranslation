import pdb

def eat(n, x):
    ret = 0

    if x == 0:
        return 0, x

    if n == 0:
        x -= 1
        return 1, x

    if allnum[n] <= x:
        x -= allnum[n]
        return pnum[n], x
        
    # eat bread
    x -= 1 
    if x == 0:
        return 0, x

    # eat n-1 beager
    tmp, x = eat(n - 1, x)
    ret += tmp
    if x == 0:
        return ret, x

    # eat patty
    x -= 1
    ret += 1
    if x == 0:
        return ret, x

    # eat n-1 beager
    tmp, x = eat(n - 1, x)
    ret += tmp
    if x == 0:
        return ret, x

    # eat bread
    x -= 1 
        
    return ret, x


def main():
    tmp = input().split()
    n = int(tmp[0])
    x = int(tmp[1])
    global pnum
    global allnum
    pnum = [1]
    allnum = [1]
    for i  in range(1, 51):
        pnum.append(pnum[i-1] * 2 + 1)
        allnum.append(allnum[i-1] * 2 + 3)

    ans, tmp = eat(n, x)

    print(ans)

        
if __name__ == '__main__':
    main()
