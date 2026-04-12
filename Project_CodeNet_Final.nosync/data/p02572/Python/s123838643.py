n = int(input())
A = [int(i) for i in input().split()]
arrsum = 0
indSum = 0
for i in A:
    arrsum += i
    indSum += i*i
arrsum = arrsum ** 2
print(((arrsum-indSum)//2)%1000000007)
