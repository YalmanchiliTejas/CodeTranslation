def resolve():
    '''
    code here
    '''
    import collections
    H, W = [int(item) for item in input().split()]

    grid = [[item for item in input()] for _ in range(H)]

    cnt = 0
    for line in  grid:
        for i in line:
            if i == '#':
                cnt += 1

    if cnt > H + W -1:
        print('Impossible')
    else:
        print('Possible')

if __name__ == "__main__":
    resolve()
