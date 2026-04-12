N = int(input())
A = list(map(int,input().split()))

A_2 = 0
for i in A:
    A_2 += i**2
    
ans = ((sum(A)**2 -A_2)//2)%(10**9 + 7)
print(ans)
