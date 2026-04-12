N = int(input())
K = int(input())

res = 0
if K == 1:
    for i in range(1,10):
        for j in range(len(str(N))):
            if i*10**j <= N:
                res += 1
if K == 2:
    for i1 in range(1,10):
        for i2 in range(1,10):
            for j1 in range(len(str(N))-1):
                for j2 in range(len(str(N))-1-j1):
                    if i1*10**(j1+j2+1)+i2*10**j2 <= N:
                        res += 1

if K == 3:
    for j1 in range(len(str(N))-2-1):
        for j2 in range(len(str(N))-2-1-j1):
            for j3 in range(len(str(N))-2-1-j1-j2):
                res += 1
    res = res * (9**3)
    
    for j1 in range(len(str(N))-2):
        for j2 in range(len(str(N))-2-j1):
            j3 = len(str(N))-2-j1-j2-1
            for i1 in range(1,10):
                for i2 in range(1,10):
                    for i3 in range(9,0,-1):
                        if i1*10**(j1+j2+j3+2)+i2*10**(j2+j3+1)+i3*10**+j3 <= N:
                            res += i3
                            break

print(res)
