N = int(input())
A = list(map(int,input().split()))
s = sum(A)**2
s -= sum(map(lambda x:x*x, A))
print(s//2 % (10**9+7))
