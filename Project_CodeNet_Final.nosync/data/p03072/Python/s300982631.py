import sys
input = sys.stdin.readline
N = int(input())
array = list(map(int, input().split()))
ans = 1
max = array[0]
for i in range(1,N):
	if max <= array[i]:
		ans += 1
		max = array[i]
print(ans)