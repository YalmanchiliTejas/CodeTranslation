N = int(input())
 
A = list(map(int, input().split()))
 
ans = sum(A) ** 2

 
for a in A:
  ans = ans - a ** 2

 
ans = ans // 2
 
print(int(ans%(10**9+7)))