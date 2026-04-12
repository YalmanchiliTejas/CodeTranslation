N = int(input())
A = [int(n) for n in input().split(" ")]

K = 1000000007

sumA = 0
for a in A:
    sumA += a
    sumA = sumA
    #print(sumA)

sumA2 = (sumA * sumA)

sumAA = 0
for a in A:
    sumAA += a * a
    #print(sumAA)
    sumAA = sumAA
    #print(sumAA)

X = (sumA2 - sumAA) // 2 % K

print(X)
    
