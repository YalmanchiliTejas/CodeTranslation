from collections import deque

n = int(input())
A = [int(a) for a in input().split()]

B = deque()
for i in range(n):
    if n%2 == 0:
        if i%2 == 0:
            B.append(A[i])
        else:
            B.appendleft(A[i])
    else:
        if i%2 == 0:
            B.appendleft(A[i])
        else:
            B.append(A[i])
        
B = list(B)
print(*B)