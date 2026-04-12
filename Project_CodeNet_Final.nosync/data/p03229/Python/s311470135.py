def main():
    N = int(input())
    array = [int(input()) for _ in range(N)]
    array.sort()

    div, mod = divmod(N, 2)
    if mod == 0:
        fore, last_in_fore, first_in_rear, rear = array[:div-1], array[div-1], array[div], array[div+1:]
        a = 2 * sum(rear) + first_in_rear - last_in_fore - 2 * sum(fore)
        print(a)
        return
    else:
        #mode1 (mfrfm):(1,-2,2,-2,1)
        fore1, mid1, rear1 = array[:div], array[div:div+2], array[div+2:]
        a1 = -2 * sum(fore1) + sum(mid1) + 2 * sum(rear1)
        #mode2 (mrfrm):(1,2,-2,2,1)
        fore2, mid2, rear2 = array[:div-1], array[div-1:div+1], array[div+1:]
        a2 = -2 * sum(fore2) - sum(mid2) + 2 * sum(rear2)

        print(max(a1, a2))
        return
    return


main()