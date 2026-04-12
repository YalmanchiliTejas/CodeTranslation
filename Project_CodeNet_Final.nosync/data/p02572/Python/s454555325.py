N = int(input())
A = [int(i) for i in input().split()]
A_sum = sum(A)
A2 = sum([i*i for i in A])
print(((A_sum * A_sum - A2)//2) % (10**9+7))
