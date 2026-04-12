def main():
    H, W = map(int, input().split())

    l = H + W - 1
    sharp = 0
    i = 0
    while i < H:
        A = str(input())
        sharp += A.count('#')
        i += 1

    if l == sharp:
        print('Possible')
    else:
        print('Impossible')

main()
