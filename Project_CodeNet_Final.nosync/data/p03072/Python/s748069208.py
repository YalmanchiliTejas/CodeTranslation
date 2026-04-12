N = int(input().rstrip())

H = [ int(n) for n in input().rstrip().split() ]

C = 0

def Maxmam(H):
    if len(H) > 0:
        M = [i for i, x in enumerate(H) if x == max(H)]
        global C
        C += len(M)

        H = H[:min(M)]
        Maxmam(H)
    else:
        C

Maxmam(H)


print(C)
