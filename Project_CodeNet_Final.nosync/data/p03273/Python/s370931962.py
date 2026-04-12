H, W = [int(x) for x in input().split()]
M = [list(input()) for _ in range(H)]

def flip(arr):

    x = len(arr[0])
    y = len(arr)

    newArr = [[None] * y for _ in range(x)]
    for xi in range(x):
        for yi in range(y):
            newArr[xi][yi] = arr[yi][xi]
    return newArr

def main():

    m = M
    m = list(filter(lambda row: any([n == '#' for n in row]), m))
    m = flip(m)

    m = list(filter(lambda row: any([n == '#' for n in row]), m))
    m = flip(m)

    for row in m:
        print(''.join(row))
    
if __name__ == '__main__':
    main()