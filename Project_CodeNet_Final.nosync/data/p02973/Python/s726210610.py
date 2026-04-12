import bisect

N = int(input())
A = []
for i in range(N):
    a = int(input())
    A.append(a)

B = [A[-1]]
del A[-1]
for a in reversed(A):
    if B[-1] <= a:
        B.append(a)
    else:
        B[bisect.bisect_right(B,a)] = a
    # print(B)



print(len(B))

