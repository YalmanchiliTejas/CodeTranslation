n = int(input())
H = list(map(int,input().split()))

count = 1
for i in range(1,len(H)):
    max_h = max(H[0:i+1])
    if max_h == H[i]:
        count += 1

print(count)