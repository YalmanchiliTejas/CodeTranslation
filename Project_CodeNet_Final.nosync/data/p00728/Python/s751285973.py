while True: 
    n = int(input())
    S = []
    if n==0:
        break
    for i in range(n):
        S.append(int(input()))
    #print(S)
    S.sort()
    #print(S)
    S.pop(0)
    S.pop()
    #print(S)

    print(sum(S)//(n-2))
