import numpy as np

N,X,M = list(map(int, input().split()))

ans = 0

check = np.zeros(M+1, dtype = int)
suuretu = []

#print(check)

for i in range(N):
    if(check[X] == 1):
        detatoko = suuretu.index(X)
        loop_sum = sum(suuretu[detatoko:])
        loop_kaisu = i - detatoko
#        print(loop_sum, loop_kaisu)

        plus_kaisu = (N - i) // loop_kaisu
        mod_plus = (N - i) % loop_kaisu

#        print(plus_kaisu, mod_plus)
        ans += loop_sum * plus_kaisu
        ans += sum(suuretu[detatoko:detatoko+mod_plus])
        break


    else:
        check[X]  = 1

    ans += X
    suuretu.append(X)

#    if(X == 0):
#        break

#    if(X == 1):
#        ans += N - 1 - i
#        break
    X = (X * X) % M

#print(check)
print(ans)
#print(suuretu)
