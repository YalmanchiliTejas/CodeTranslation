# input
n = int(input())
H = [int(i) for i in input().split()]

# main
ans = 0
for i in range(n):
  if max(H[:i+1]) == H[i]:
    ans += 1
  
# output
print(ans)