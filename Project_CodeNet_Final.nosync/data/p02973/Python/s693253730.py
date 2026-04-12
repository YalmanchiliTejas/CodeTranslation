n = int(input())
A = [int(input()) for _ in range(n)]

B = []
import bisect
for i, a in enumerate(A):
    if len(B) == 0:
        B.append(-a)
    else:
        j = bisect.bisect_right(B, -a)
        #print(j)
        if j == len(B):
            B.append(-a)
        elif j == 0:
            B[0] = -a
        else:
            B[j] = -a
    #print(B)
#print(B)
print(len(B))
