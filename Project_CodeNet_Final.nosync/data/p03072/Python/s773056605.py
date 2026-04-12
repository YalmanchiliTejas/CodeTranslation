N = int(input())
H = list(map(int,input().split()))

ans = 0
for i in range(N):
 judge = 1
 for j in range(0,i+1):
   if(H[i] < H[j]): 
     judge = 0
 if(judge == 1):
  ans += 1
print(ans)