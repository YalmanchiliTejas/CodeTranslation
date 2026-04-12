N = int(input())
A_in = [int(input()) for _ in range(N)] 
 
A = sorted(A_in)
res1 = 0
A2 = []
for i in range(len(A)):
    if len(A) == 1:
        if abs(A[0] - A2[0]) < abs(A[0] - A2[-1]):
            A2.append(A[0])
        else:
            A2.insert(0,A[0])
        break
    if i % 2 == 0:
        A2.append(A.pop(-1))
    else:
        A2.append(A.pop(0))
for i in range(len(A2)-1):
    res1 += abs(A2[i] - A2[i+1])

A = sorted(A_in,reverse=True)
res2 = 0
A2 = []
for i in range(len(A)):
    if len(A) == 1:
        if abs(A[0] - A2[0]) < abs(A[0] - A2[-1]):
            A2.append(A[0])
        else:
            A2.insert(0,A[0])
        break
    if i % 2 == 0:
        A2.append(A.pop(-1))
    else:
        A2.append(A.pop(0))
for i in range(len(A2)-1):
    res2 += abs(A2[i] - A2[i+1])

print(max(res1,res2))