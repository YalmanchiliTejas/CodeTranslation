N = int (input ())
S = str (input ())
K = int (input ())

num = ord (S [K - 1])

for i in range (N):
    if ord (S [i]) == num:
        print (S [i], end = '')
    else:
        print ('*', end = '')
