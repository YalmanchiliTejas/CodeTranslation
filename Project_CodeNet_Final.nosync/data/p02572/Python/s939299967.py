n = int(input())
l = list(map(int,input().split())) 

totalsqr = (sum(l))**2

individualsqrsum=0
for i in l:
    individualsqrsum += i**2

ans = (totalsqr  - individualsqrsum)  // 2 
ans = ans%(10**9 + 7)
print(ans)