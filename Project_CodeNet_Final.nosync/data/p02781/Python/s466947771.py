def main(N,K):

    if K == 1:
        return int(N[0]) + 9 * (len(N)-1)
    if K == 2:
        if len(N) == 1:
            return 0
        less = (len(N)-1) * (len(N)-2) // 2 * 9 * 9
        mid = (len(N)-1) * 9 * (int(N[0])-1)
        for i in range(1,len(N)):
            if N[i] != "0":
                break
        one = main(N[i:],1)
        return less+mid+one
    if K == 3:
        if len(N) < 3:
            return 0
    less = (len(N)-1) * (len(N)-2) * (len(N)-3) // 6 * 9 * 9 * 9
    mid = (int(N[0])-1) * (len(N)-1) * (len(N)-2) // 2 * 9 * 9
    for i in range(1,len(N)):
        if N[i] != "0":
            break
    one = main(N[i:],2)
    return (less+mid+one)
        
print(main(input(),int(input())))
