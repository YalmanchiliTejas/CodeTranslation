N = int(input())
A_List = [int(i) for i in input().split()]

Y = 0
M = 10**9+7
tempSum = sum(A_List)

for x in A_List:
    tempSum -= x
    Y += x * tempSum
    Y = Y%M
print(Y)