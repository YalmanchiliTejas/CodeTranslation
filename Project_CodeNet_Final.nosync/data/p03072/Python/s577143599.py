N = int(input())
H = list(map(int,input().split()))
count = 1
x = H[0]
for i in range(N-1):
     if x <=H[i+1]:
         x = H[i+1]
         count += 1

print(count)
     
