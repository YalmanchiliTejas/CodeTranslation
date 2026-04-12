while True :
    num = int(input())
    if num == 0 :
        break
    A = []
    for i in range(num):
        sco = int(input())
        A.append(sco)
        A.sort()
    del A[num - 1]
    del A[0]

    B = int(sum(A)/(num-2))
    print(B)
