N = int(input())
A = list(map(int, input().split()))

M = 10 ** 9 + 7
T = sum(map(lambda x: x**2, A))
print (((sum(A)**2-T)//2)%M)