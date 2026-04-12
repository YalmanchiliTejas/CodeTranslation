N = int(input())
H = list(map(int,input().split()))

ans = 1
for h in range(1,len(H),1):
  ryokan = H[h]
  max_mt = max(H[:h])
  if ryokan >= max_mt:
    ans += 1

print(ans)