N = int(input())
A_list = list(map(int, input().split()))
#myans_list =  [ [0 for n in range(N)] for nn in range(N) ]
#myans = 0
#for n in range(N):
#    for nn in range(N):
#        myans_list[n][nn] = A_list[n] * A_list[nn]
#for n in myans_list:
#    print(n)
mysum = sum(A_list)
myans = 0
for n in range(N-1):
    mysum -= A_list[n]
    myans +=  mysum*A_list[n]
print(myans%(1000000007))