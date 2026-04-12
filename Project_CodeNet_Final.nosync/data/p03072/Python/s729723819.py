N = int(input())
H = [int(i) for i in input().split(" ")]
ans = 1
for i in range(N -1):
  if H[i + 1] >= max(H[:i+1]):
    ans += 1
print(ans)