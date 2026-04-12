N = int(input())
H = list(map(int, input().split()))

n=0
maxh = H[0]
for i in range(N):
    if(maxh<=H[i]):
        n+=1
        maxh=H[i]
print(n)
