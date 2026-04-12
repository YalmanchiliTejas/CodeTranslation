from sys import stdin
N = int(stdin.readline().rstrip())
s_data = stdin.readline().rstrip().split()
height = [int(itr) for itr in s_data]
ans = 1
for h in range(0,N):
    if h == 0:
        continue
    if height[h] >= max(height[:h]):
        ans += 1
print(ans)