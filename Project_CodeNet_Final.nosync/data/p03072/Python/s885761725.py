n = int(input())
m = list(map(int,input().split()))
ans = 1
for i in range(1,n):
     flag = 0
     for j in range(i):
          if m[j] > m[i]:
               flag = 1
               break
     if flag == 0:
          ans += 1
print(ans)