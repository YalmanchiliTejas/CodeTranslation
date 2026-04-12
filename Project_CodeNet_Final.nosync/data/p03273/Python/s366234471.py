
H, W = map(int,input().split())

a = []

for i in range(H):

    newa = input()
    newa_l = list(newa)
    a.append(newa_l)

bigbul = True
while bigbul:

    bigbul = False
    acp = a.copy()
    
    for i in range(H):
    
        bul = True
        for j in range(W):

            if a[i][j] != ".":
                bul = False
                break

        if bul:
            del acp[i]
            a = acp.copy()
            H -= 1
            bigbul = True
            break

bigbul = True
while bigbul:

    bigbul = False
    acp = a.copy()

    #print("W", W)

    for j in range(W):

        bul = True

        for i in range(H):

            if a[i][j] != ".":
                bul = False
                break


        if bul:

            for k in acp:

                del k[j]
                #print ("nowk")

                #for i in acp:
                    #ans = "".join(i)
                    #print (ans)

            a = acp.copy()
            W -= 1
            bigbul = True
            break

for i in a:
    ans = "".join(i)
    print (ans)

    
