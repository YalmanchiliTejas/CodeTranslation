
N = int(input())

A = list(map(int,input().split()))

if N % 2 == 0:

    e = 0
    o = 0
    

    for i in range(N):

        if i % 2 == 0:
            e += A[i]
        else:
            o += A[i]

    el = [0]
    ol = [0]

    for i in range(N):

        if i % 2 == 0:
            el.append(el[-1] + A[i])
        else:
            ol.append(ol[-1] + A[i])

    eri = [0]
    ori = [0]

    for i in range(N-1,-1,-1):

        if i % 2 == 0:
            eri.append(eri[-1] + A[i])
        else:
            ori.append(ori[-1] + A[i])

    ans = max(e,o)


    for i in range(N//2+1):
        ans = max(ans,el[i]+ori[N//2-i])
    print (ans)

else:

    el = [0]
    ol = [0]

    for i in range(N):

        if i % 2 == 0:
            el.append(el[-1] + A[i])
        else:
            ol.append(ol[-1] + A[i])

    eri = [0]
    ori = [0]

    for i in range(N-1,-1,-1):

        if i % 2 == 0:
            eri.append(eri[-1] + A[i])
        else:
            ori.append(ori[-1] + A[i])

    ans = float("-inf")



    LS = [0]
    LSM = [0]
    for i in range(0,N-1,2):

        LS.append(LS[-1] + A[i] - A[i+1])
        LSM.append(max(LSM[-1],LS[-1]))

    RS = [0]
    RSM = [0]
    for i in range(N-1,0,-2):

        RS.append(RS[-1] + A[i] - A[i-1])
        RSM.append(max(RSM[-1],RS[-1]))

    EOE = float("-inf")
    for i in range(N//2+1):
        EOE = max(EOE , LSM[i] + RSM[N//2-i])

    
    for i in range(N):

        if i <= N//2:

            ans = max(ans , el[i]+ori[N//2-i] , ol[i]+eri[N//2-i] , el[i]+eri[N//2-i] , ol[-1] + EOE)

    print (ans)