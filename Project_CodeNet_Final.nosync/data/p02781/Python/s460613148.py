
N = input()

K = int(input())

lis =  [ [ [0,0] for i in range(K+1) ] for j in range(len(N) + 1) ]

#桁/0以外が出た個数/密着フラグ

lis[0][0][0] = 1

for i in range(len(N)):

    nketa = int(N[i])

    for num in range(K):

        for flag in range(2):


            if num == 0 and flag == 0:

                lis[i+1][num+1][0] += lis[i][num][flag]
                lis[i+1][num+1][1] += (nketa - 1) * lis[i][num][flag]
                lis[i+1][num][1] += lis[i][num][flag]

            if num != K and flag == 0:

                if nketa == 0:
                    lis[i+1][num][0] += lis[i][num][flag]
                else:
                    lis[i+1][num+1][0] += lis[i][num][flag]
                    lis[i+1][num][1] += lis[i][num][flag]
                    lis[i+1][num+1][1] += lis[i][num][flag] * (nketa - 1)
                

            if num != K and flag == 1:

                lis[i+1][num+1][1] += 9 * lis[i][num][flag]
                lis[i+1][num][1] += lis[i][num][flag]

ans = 0

#print (lis)

for i in range(len(N) + 1):

    for j in range(2):

        ans += lis[i][K][j]

print (ans //2 )