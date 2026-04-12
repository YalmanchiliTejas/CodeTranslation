M = ['North','East','West','South','Right','Left']
while 1:
    n = int(input())
    if n == 0:
        break
    D = [1,2,3]
    s = 1
    for i in range(n):
        m = input()
        if m == M[0]:
            D[0],D[1] = D[1],7-D[0]
        elif m == M[1]:
            D[0],D[2] = 7-D[2],D[0]
        elif m == M[2]:
            D[0],D[2] = D[2],7-D[0]
        elif m == M[3]:
            D[0],D[1] = 7-D[1],D[0]
        elif m == M[4]:
            D[1],D[2] = D[2],7-D[1]
        else:
            D[1],D[2] = 7-D[2],D[1]
        s += D[0]
    print (s)

