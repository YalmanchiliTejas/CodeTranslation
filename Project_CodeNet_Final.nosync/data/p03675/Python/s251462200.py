N = int(input())

A = list(input().split())

if N==1:
    print(A[0])
else:
    side1 = A[0::2]
    side2 = A[1::2]
    if N%2==0:
        print(" ".join(side2[::-1]+side1))
    else:
        print(" ".join(side1[::-1]+side2))