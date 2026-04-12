n = int(input())
#a, b = map(int,input().split())
al = list(map(int, input().split()))
#l = [list(map(int,input().split())) for i in range(n)]
mod = 10**9+7
cuml = [al[0]]
for i in range(n-2):
    cuml.append((cuml[i]+al[i+1]) % mod)
ans = 0
for i in range(1, n):
    ans = (ans+cuml[i-1]*al[i]) % mod
print(ans)
