N = int(input())
A = list(input().split())
B = [int(a) for a in A]
x = 10**9+7
summation1 = sum(B) ** 2
summation2 = sum(b ** 2 for b in B)
summation = ((summation1 - summation2) // 2) % x
print(summation)
