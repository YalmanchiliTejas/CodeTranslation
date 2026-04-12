N = int(input())
H = list(map(int, input().split()))
ryokan = 0

for i in range(N):
    cutH = H[:i+1]
    if max(cutH) == H[i]:
        ryokan += 1
        
print(ryokan)