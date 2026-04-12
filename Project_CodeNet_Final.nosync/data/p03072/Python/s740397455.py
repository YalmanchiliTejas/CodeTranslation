N = int(input())
H = list(map(int, input().split()))

counter = 0

for i in range(len(H)):
    
    if (max(H[0:i+1]) == H[i]):
        
        counter += 1
        
print(counter)