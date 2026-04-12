def main():
    n, x, m = map(int, input().split())
    inlis = list()
    inlis.append(x)
    mae = x
    kaisuu = 0

    for j in range(n-1):
        tsugi = mae ** 2 % m
        #print(tsugi)
        if tsugi not in inlis:
            inlis.append(tsugi)
            mae = tsugi
        else:
            inlis.append(tsugi)
            kaisuu = j+1
            bangou = inlis.index(tsugi)
            loop = len(inlis[bangou:-1])
            #print(kaisuu, bangou, loop)
            break
    #print(inlis)
    if kaisuu == 0:
        print(sum(inlis))
    else:
        #print(loop, n, bangou)
        loopnum = (n - bangou) // loop
        amari = (n - bangou) % loop
        if amari > 0:
            #print(inlis[:bangou],loopnum,inlis[bangou:-1],inlis[bangou:bangou+amari])
            print(sum(inlis[:bangou])+loopnum*sum(inlis[bangou:-1])+sum(inlis[bangou:bangou+amari]))
        else:
            print(sum(inlis[:bangou])+loopnum*sum(inlis[bangou:-1]))

        



if __name__ == "__main__":
    main()
