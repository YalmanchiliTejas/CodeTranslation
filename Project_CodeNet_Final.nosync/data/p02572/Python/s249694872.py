N = int(input())
A = list(map(int,input().split()))

S = sum(A)
S2 = sum(map(lambda x: x*x,A))
ans = ((S*S - S2)//2)%1000000007
print(int(ans))