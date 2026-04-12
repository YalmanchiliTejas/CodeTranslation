n = input()
A = raw_input().split()
B = A[0::2]
C = A[1::2]
if n % 2 == 1:
    print " ".join(B[::-1] + C)
else:
    print " ".join(C[::-1] + B)
