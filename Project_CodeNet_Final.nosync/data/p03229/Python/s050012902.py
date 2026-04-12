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
        #mode1 (mrfrm):(1,2,-2,2,1)
        array1=array[:]
        fore1=[]
        rear1=[]
        while True:
            fore1.append(array1.pop(0))
            if len(array1) <= 2:
                break
            rear1.append(array1.pop(-1))
        mid1 = array1
        a1 = 2 * sum(rear1) + sum(mid1) - 2 * sum(fore1)

        #mode2 (mfrfm):(1,-2,2,-2,1)
        array2 = array[:]
        fore2=[]
        rear2=[]
        while True:
            rear2.append(array2.pop(-1))
            if len(array2) <= 2:
                break
            fore2.append(array2.pop(0))
        mid2 = array2
        a2 = 2 * sum(rear2) - sum(mid2) - 2 * sum(fore2)

        print(max(a1, a2))
        return
    return


main()