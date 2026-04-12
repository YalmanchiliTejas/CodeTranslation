N, X, M = map(int, input().split())

Visited = [0]*(M+1)
latestvisit = [0]*(M+1)
count = 0
latest = 0
proper = 0
        
for i in range (0, N):
	if Visited[X] > 0:
		latest = X
		latestvisit[X] = i
		proper = 1
		break
	latestvisit[X] = i
	Visited[X]+= 1
	X = (X**2)%M

for j in range (0, M+1):
	count+=(j*Visited[j])

if proper == 0:
	print(count)
	exit()
    
P = sum(Visited)
A = latestvisit[X]
B = latestvisit[(X**2)%M]
slouch = 0

for i in range (0, M):
	if latestvisit[i] >=B and latestvisit[i] <= A:
		slouch+=i

count+=((N-P)//(A-B+1))*slouch


for i in range (0, (N-P)%(A-B+1)):
	count+=X
	X = (X**2)%M

print(count)