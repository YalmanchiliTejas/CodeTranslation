from copy import copy
N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
A1 = copy(A)
A2 = copy(A)
B1 = []
B2 = []
i=0
while A1 and A2:
    if i%2 == 0:
        B1.append(A1.pop(0))
        B2.append(A2.pop(-1))
    else:
        B1.append(A1.pop(-1))
        B2.append(A2.pop(0))
    i += 1
B1.append(B1[0])
B2.append(B2[0])
C1 = [abs(B1[i+1]-B1[i]) for i in range(len(B1)-1)]
C2 = [abs(B2[i+1]-B2[i]) for i in range(len(B2)-1)]
print(max(sum(C1)-min(C1),sum(C2)-min(C2)))