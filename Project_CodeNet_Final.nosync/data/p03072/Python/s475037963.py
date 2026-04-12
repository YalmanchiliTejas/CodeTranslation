import sys

N = int(input())
line = list(map(int,input().split()))

ans = 1
mx = line[0]


for i in range(1,line.index(max(line))):
	if line[i] >= mx:
		ans += 1
		mx = line[i]

for i in range(line.index(max(line)),len(line)):
	if i != 0 and line[i] == max(line):
		ans += 1

print(ans)
