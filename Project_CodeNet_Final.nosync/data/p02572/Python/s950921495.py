import sys
input = sys.stdin.readline
mod = int(1e9+7)
n=int(input())
L=list(map(int,input().split()))
total = 0
hb = sum(L)
val = 0
for i in range(n-1):
    val +=L[i]
    total += L[i]*(hb-val)
print(total%mod)



