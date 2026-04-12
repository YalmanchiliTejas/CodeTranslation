
while True:
    

    n,l,r = map(int,input().split())

    ans = 0

    if n == 0 and l == 0 and r == 0:
        break

    A = []

    for i in range(n):

        a = int(input())

        A.append(a)


    for x in range(r-l+1):

        x += l

        #print (x)

        for i in range(len(A)):

            
            flag = True

            if x % A[i] == 0:

                if i % 2 == 0:
                    ans += 1
                   # print (x,"は",A[i],i)


                #print (x,"はだめ",A[i],i)
                flag = False
                break

        if flag and len(A) % 2 == 0:

            #print (x , "x")

            ans += 1


    print (ans)
