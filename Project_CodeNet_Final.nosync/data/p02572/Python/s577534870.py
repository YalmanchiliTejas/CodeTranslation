N = int(input())
A = list(map(int,input().split()))
mod = 1000000000 + 7
S = sum(A)
S2 = sum(map(lambda x: x*x,A))
ans = (S*S - S2)// 2 % mod
print(ans)