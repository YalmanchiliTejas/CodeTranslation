N = int(input())
A = list(map(int,input().split()))
tasizann = 0
for i in range (N):
 tasizann = tasizann + A[i]
nijou = tasizann**2
nijouwa = 0
for i in range (N):
 nijouwa =nijouwa + A[i]**2
ans = (nijou - nijouwa)//2
ans = ans % (10**9+7)
print (ans)