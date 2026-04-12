N =input()
N = int(N)
p = list(map(int,input().split()))
count = 1
x=p[0]
for i in range(N-1):
    if p[i+1] >= x:
        x=p[i+1]
        count += 1
print(count)
