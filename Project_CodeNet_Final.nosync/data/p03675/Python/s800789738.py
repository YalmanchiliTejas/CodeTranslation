N = int(input())
A = list(map(int, input().split()))
A.reverse()
B = []
C = []
for i, a in enumerate(A):
    if i%2==0:
        B.append(a)
    else:
        C.append(a)
print(*(B+list(reversed(C))))
