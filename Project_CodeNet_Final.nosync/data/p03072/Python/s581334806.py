N = int(input())
H = input().split()
h = [int(k) for k in H]
l = []
ans = 1
for i in range(len(H)-1):
  l.append(h[i])
  
  if h[i+1] >= max(l):
    ans += 1
  
print(ans)