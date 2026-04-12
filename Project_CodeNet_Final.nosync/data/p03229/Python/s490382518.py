import sys
input = sys.stdin.readline


n = int(input())
L = [int(input()) for _ in range(n)]
L.sort()
n_2 =n // 2

ans = 0
if n % 2 == 1:
    ans = 2*sum(L[n_2+1:])-2*sum(L[:n_2-1])-L[n_2-1]-L[n_2]
    ans_2 = 2*sum(L[n_2+2:])-2*sum(L[:n_2])+L[n_2+1]+L[n_2]
    ans = max(ans,ans_2)
else:
    ans = 2*sum(L[n_2+1:])-2*sum(L[:n_2-1])+L[n_2]-L[n_2-1]
    

print(ans)
