n = int(input())
h_list = list(map(int,input().split()))
ans = 1
for i in range(1,n):
  
  if h_list[i] >= max(h_list[:i]):

    ans += 1
print(ans)